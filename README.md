# C boilerplate project

## Contains:
 - ```arg.c```,```arg.h```: Minimal getopt template
 - ```assrt.h```,```assrt.c```: Assert
 - ```exitCodes.h```: exit codes
 - ```global.h```: global definitions, included in every compile unit
 - ```log.c```,```log.h```: asynchronous logging
 - ```stdext.c```,```stdext.h```: extensions to the standard (strnlen, strrev, itoa, async io)
 - ```lt.c```,```lt.h```: lifetime functions, ```init()```: called first, ```cleanUp(int ret)```: called last
 - ```arr.c```,```arr.h```: Array_t implementation
 - ```error.c```,```error.h```: Rust like Option, unwrap, except
 - ```main.c```: main()

