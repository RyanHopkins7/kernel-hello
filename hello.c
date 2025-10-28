#include <stdio.h>

// Test the syscalls made by the humble printf function
// compile: gcc -Wall -o hello hello.c
// run: strace ./hello

int main(void)
{
    printf("hello");
    return 0;
}

// Output from strace:
// $ strace ./hello
// execve("./hello", ["./hello"], 0x7ffd33dfca00 /* 42 vars */) = 0
// brk(NULL)                               = 0x36fcd000
// mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7ff9db80a000
// access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
// openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
// fstat(3, {st_mode=S_IFREG|0644, st_size=44663, ...}) = 0
// mmap(NULL, 44663, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7ff9db7ff000
// close(3)                                = 0
// openat(AT_FDCWD, "/lib64/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
// read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P\247\2\0\0\0\0\0"..., 832) = 832
// pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
// fstat(3, {st_mode=S_IFREG|0755, st_size=2335624, ...}) = 0
// pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
// mmap(NULL, 1932304, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7ff9db627000
// mmap(0x7ff9db64f000, 1372160, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x7ff9db64f000
// mmap(0x7ff9db79e000, 339968, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x177000) = 0x7ff9db79e000
// mmap(0x7ff9db7f1000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1c9000) = 0x7ff9db7f1000
// mmap(0x7ff9db7f7000, 31760, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7ff9db7f7000
// close(3)                                = 0
// mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7ff9db624000
// arch_prctl(ARCH_SET_FS, 0x7ff9db624740) = 0
// set_tid_address(0x7ff9db624a10)         = 26356
// set_robust_list(0x7ff9db624a20, 24)     = 0
// rseq(0x7ff9db625060, 0x20, 0, 0x53053053) = 0
// mprotect(0x7ff9db7f1000, 16384, PROT_READ) = 0
// mprotect(0x403000, 4096, PROT_READ)     = 0
// mprotect(0x7ff9db844000, 8192, PROT_READ) = 0
// prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
// munmap(0x7ff9db7ff000, 44663)           = 0
// fstat(1, {st_mode=S_IFCHR|0620, st_rdev=makedev(0x88, 0x3), ...}) = 0
// getrandom("\x73\xc5\x82\x8e\x72\x73\xee\x03", 8, GRND_NONBLOCK) = 8
// brk(NULL)                               = 0x36fcd000
// brk(0x36fee000)                         = 0x36fee000
// write(1, "hello", 5hello)                    = 5
// exit_group(0)                           = ?
// +++ exited with 0 +++

