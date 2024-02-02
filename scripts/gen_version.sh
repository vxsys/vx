#!/bin/sh
# argv[1]: version
# argv[2]: machine
# argv[3]: sysname

printf "/* generated automatically */\n"
printf "/* warning: changes will be lost */\n"

printf "#include <kern/version.h>\n"

printf "const char sysname[] = \"${3:-VX/sys}\";\n"
printf "const char release[] = \"${1}\";\n"
printf "const char version[] = \"$(LC_ALL=C date +'%Y-%m-%d %H:%M:%S%z')\";\n"
printf "const char machine[] = \"${2}\";\n"