/* Entry Point */
ENTRY( Reset_Handler )

/* Memory layout */
MEMORY
{
    RAM (xrw) : ORIGIN = 0x20000000, LENGTH = 16K
    ROM (rx)  : ORIGIN = 0x08000000, LENGTH = 128K
}

/* Highest address of the user mode stack */
_estack = ORIGIN(RAM) + LENGTH(RAM) /* end of RAM */

/* Sections layout */
SECTIONS
{
    .isr_vector :
    {
        KEEP(*(.isr_vector))
    } >ROM

    /* The program code and other data into ROM memory */
    .text :
    {
        . = ALIGN(4);
        *(.text)
    } >ROM

    /* Constant data into ROM memory */
    .rodata:
    {
        . = ALIGN(4);
        *(.rodata)
    } >ROM

    _sidata = LOADADDR(.data);
    /* Initialized data sections into RAM memory */
    .data :
    {
        . = ALIGN(4);
        _sdata = .;
        *(.data) /* .data section */
        . = ALIGN(4);
        _edata = .;
    } >RAM AT >ROM

    /* Uninitialized data section into RAM memory */
    .bss :
    {
        . = ALIGN(4);
        _sbss = .;
        *(.bss)
        . = ALIGN(4);
        _ebss = .;
    } >RAM
}
