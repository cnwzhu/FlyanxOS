/* Copyright (C) 2007 Free Software Foundation, Inc. 
 * See the copyright notice in the file /usr/LICENSE.
 * Created by flyan on 2019/12/12.
 * QQ: 1341662010
 * QQ-Group:909830414
 * gitee: https://gitee.com/flyanh/
 *
 * 提供给用户进程的posix调用：读取一个文件。
 */

#include <lib.h>
#define read    _read
#include <unistd.h>

PUBLIC ssize_t read(
        int fd,         /* 文件描述符 */
        void *buffer,   /* 要读到哪呢？ */
        size_t bytes    /* 要读多少字节？ */
){
    Message out;

    out.m1_i1 = fd;
    out.m1_i2 = bytes;
    out.m1_p1 = (char *)buffer;
    return _syscall(FS, READ, &out);
}
