savedcmd_/home/localadmin/kernel-hello/hello-1.mod := printf '%s\n'   hello-1.o | awk '!x[$$0]++ { print("/home/localadmin/kernel-hello/"$$0) }' > /home/localadmin/kernel-hello/hello-1.mod
