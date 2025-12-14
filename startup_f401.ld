ENTRY(Reset_Handler)

MEMORY 
{
    FLASH(rx):ORIGIN =0x08000000,LENGTH =256K
    SRAM(rwx):ORIGIN =0x20000000,LENGTH =64K
}

SECTIONS
{
    .text :
    {
        *(.isr_vector)
        *(.text)
        *(.rodata)
        . = ALIGN(4);
        end_of_text = .;
    }>FLASH

    flash_data = LOADADDR(.data);

    .data :
    {   
        _s_data = .;
        *(.data)
        . = ALIGN(4);
        _e_data = .;
    } > SRAM AT> FLASH

    .bss :
    {
        _s_bss = .;
        *(.bss)
        . = ALIGN(4);
        _e_bss = .;
    }>SRAM
}