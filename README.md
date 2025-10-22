# kernel-hello
Hello world as a Linux kernel module

### Headers
First, you will need to install the headers files for the kernel. (See this guide)[https://sysprog21.github.io/lkmpg/]

### Compile
```make
modinfo hello-1.ko```

Should output:
```filename:       /home/(username)/kernel-hello/hello-1.ko
description:    Hello world kernel module
author:         Ryan Hopkins
license:        GPL
rhelversion:    10.2
srcversion:     D1E0AFF95AC7A6C997FFCFB
depends:        
name:           hello_1
retpoline:      Y
vermagic:       6.12.0-142.el10.x86_64 SMP preempt mod_unload modversions```

### Load and unload module
```sudo insmod hello-1.ko
sudo rmmod hello_1```

Now, you should be able to see the message in the kernel ring buffer:
```username@hostname:~/kernel-hello$ sudo dmesg | tail -2
[  866.546661] Hello, world!
[  911.866931] Goodbye, world!```

### Source
https://sysprog21.github.io/lkmpg/
