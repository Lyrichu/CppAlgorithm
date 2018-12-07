/*
 * Created by lyrichu on 18-12-8.
 */
#include "zlib.h"
#include <iostream>
#include <cstring>

const int MAX_BUFFER_SIZE = 99999;
const char* INPUT_FILE_PATH = "/home/lyrichu/CppAlgorithm/resource/textfiles/log.txt";
const char* SAVE_COMPRESS_PATH = "/home/lyrichu/CppAlgorithm/resource/textfiles/log.compress.zip";
const char* SAVE_UNCOMPRESS_PATH = "/home/lyrichu/CppAlgorithm/resource/textfiles/log.uncompress.txt";

// 压缩文件
void compressFile(const char*, const char*);
//解压缩
void uncompressFile(const char*, const char*);

int main(int arc,char* argv[]) {
    compressFile(INPUT_FILE_PATH,SAVE_COMPRESS_PATH);
    uncompressFile(SAVE_COMPRESS_PATH,SAVE_UNCOMPRESS_PATH);
    return 0;
}

/*
 * 压缩文件
 * @param input_file:输入文件路径
 * @param compress_file:压缩文件路径
 * @return: void
 */
void compressFile(const char* input_file, const char* compress_file) {
    FILE* f_src;
    FILE* f_compress;
    unsigned long len_src; // 源文件长度
    unsigned long len_compress; // 压缩文件长度
    auto buffer_src = new unsigned char[MAX_BUFFER_SIZE];
    auto buffer_compress = new unsigned char[MAX_BUFFER_SIZE];

    // 打开文件
    f_src = fopen(input_file,"r");
    // 打开写入的压缩文件
    f_compress = fopen(compress_file,"w");
    // 读取文件
    len_src = fread(buffer_src, sizeof(char),MAX_BUFFER_SIZE,f_src);
    // 压缩
    compress(buffer_compress,&len_compress,buffer_src,len_src);
    // 写入压缩文件
    fwrite(buffer_compress, sizeof(char),len_compress,f_compress);
    // 打印压缩前以及压缩后的大小
    std::cout<<"src file("<<input_file<<") size:"<<len_src<<std::endl;
    std::cout<<"compress file("<<compress_file<<") size:"<<len_compress<<std::endl;
    // 关闭文件句柄
    fclose(f_src);
    fclose(f_compress);
}

/*
 * 解压缩文件
 */

void uncompressFile(const char* compress_file, const char* uncompress_file) {
    FILE* f_compress;
    FILE* f_uncompress;
    unsigned long len_compress;
    unsigned long len_uncompress;
    f_compress = fopen(compress_file,"r");
    f_uncompress = fopen(uncompress_file,"w");

    auto buffer_compress = new unsigned char[MAX_BUFFER_SIZE];
    auto buffer_uncompress = new unsigned char[MAX_BUFFER_SIZE];
    // 读取压缩文件
    len_compress = fread(buffer_compress, sizeof(char),MAX_BUFFER_SIZE,f_compress);
    // 解压缩
    uncompress(buffer_uncompress,&len_uncompress,buffer_compress,len_compress);
    // 写入解压缩文件
    fwrite(buffer_uncompress, sizeof(char),len_uncompress,f_uncompress);
    std::cout<<"compress file("<<compress_file<<") size:"<<len_compress<<std::endl;
    std::cout<<"uncompress file("<<uncompress_file<<") size:"<<len_uncompress<<std::endl;
    // 关闭文件句柄
    fclose(f_compress);
    fclose(f_uncompress);
}


