MEMORY {
    /* >>> 在这里定义内存区域，设置内存区域起始地址为 `0x8000000`，长度为 `0x2000`。 */

    /* <<< */
}


SECTIONS {
    .text : {
        *(.text)
        /* 其他段的定义 */
    }


    /* 定义只读数据段，包含常量数据 */
    .rodata : {
        *(.rodata)
    } > RAM

    /* 定义BSS段，包含未初始化的全局变量和静态变量 */
    .bss : {
        *(.bss)
    } > RAM

    /* >>> 在这里添加 my_custom_sectoin，并在其内放置 `my_custom_data`，地址设置 0x1234 。*/

    /* <<< */


    /* 定义程序头表 */
    . = ALIGN(4);
    .interp : { *(.interp) }
    .note.gnu.build-id : { *(.note.gnu.build-id) }
    .dynamic : { *(.dynamic) }
    .hash : { *(.hash) }
    .gnu.hash : { *(.gnu.hash) }
    .dynsym : { *(.dynsym) }
    .dynstr : { *(.dynstr) }
    .gnu.version : { *(.gnu.version) }
    .gnu.version_d : { *(.gnu.version_d) }
    .gnu.version_r : { *(.gnu.version_r) }
    .eh_frame : { *(.eh_frame) }
    . = ALIGN(8);
    . = . + SIZEOF_HEADERS;
}
