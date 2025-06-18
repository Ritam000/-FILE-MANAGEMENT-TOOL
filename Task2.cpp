#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>

const int BLOCK_SIZE = 1024 * 1024; // 1MB per block
std::mutex file_mutex;

// Naive Run-Length Encoding compression
std::string rle_compress(const std::string &data)
{
    std::string compressed;
    size_t len = data.length();
    for (size_t i = 0; i < len;)
    {
        char current = data[i];
        size_t count = 1;
        while (i + count < len && data[i + count] == current && count < 255)
        {
            count++;
        }
        compressed += static_cast<char>(count);
        compressed += current;
        i += count;
    }
    return compressed;
}

// Thread function to read, compress, and store a block
void compress_block(std::ifstream &file, std::vector<std::string> &results, int block_index, int total_blocks)
{
    std::vector<char> buffer(BLOCK_SIZE);
    {
        std::lock_guard<std::mutex> lock(file_mutex);
        file.seekg(block_index * BLOCK_SIZE);
        file.read(buffer.data(), BLOCK_SIZE);
    }

    std::string input_data(buffer.data(), file.gcount());
    std::string compressed_data = rle_compress(input_data);
    results[block_index] = compressed_data;
}

int main()
{
    std::ifstream infile("input.txt", std::ios::binary);
    if (!infile)
    {
        std::cerr << "Cannot open input file.\n";
        return 1;
    }

    infile.seekg(0, std::ios::end);
    std::streamsize file_size = infile.tellg();
    infile.seekg(0, std::ios::beg);

    int block_count = (file_size + BLOCK_SIZE - 1) / BLOCK_SIZE;
    std::vector<std::string> compressed_blocks(block_count);
    std::vector<std::thread> threads;

    for (int i = 0; i < block_count; ++i)
    {
        threads.emplace_back(compress_block, std::ref(infile), std::ref(compressed_blocks), i, block_count);
    }

    for (auto &t : threads)
        t.join();

    std::ofstream outfile("compressed_output.rle", std::ios::binary);
    for (const auto &block : compressed_blocks)
    {
        uint32_t size = block.size();
        outfile.write(reinterpret_cast<const char *>(&size), sizeof(size)); // Block size
        outfile.write(block.data(), size);                                  // Block data
    }

    std::cout << "Compression complete. Compressed " << block_count << " blocks.\n";
    // After determining file_size:
    std::cout << "Original file size: " << file_size << " bytes\n";

    // ... [compression happens here] ...

    // After writing to output file
    outfile.close(); // ensure file is flushed and closed

    std::ifstream result("compressed_output.rle", std::ios::binary | std::ios::ate);
    std::streamsize compressed_size = result.tellg();
    result.close();

    std::cout << "Compressed file size: " << compressed_size << " bytes\n";

    double ratio = 100.0 * (1.0 - (double)compressed_size / file_size);
    std::cout << "Compression ratio: " << ratio << "%\n";

    return 0;
}
