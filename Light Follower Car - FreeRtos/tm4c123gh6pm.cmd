/******************************************************************************
 *
 * Default Linker Command file for the Texas Instruments TM4C123GH6PM
 *
 * This is derived from revision 15071 of the TivaWare Library.
 *
 *****************************************************************************/

--retain=g_pfnVectors

MEMORY
{
    FLASH (RX) : origin = 0x00000000, length = 0x00040000
    SRAM (RWX) : origin = 0x20000000, length = 0x00008000
}

/* The following command line options are set as part of the CCS project.    */
/* If you are building using the command line, or for some reason want to    */
/* define them here, you can uncomment and modify these lines as needed.     */
/* If you are using CCS for building, it is probably better to make any such */
/* modifications in your CCS project and leave this file alone.              */
/*                                                                           */
/* --heap_size=0                                                             */
/* --stack_size=256                                                          */
/* --library=rtsv7M4_T_le_eabi.lib                                           */

/* Section allocation in memory */

SECTIONS
{
    .intvecs:   > 0x00000000
    .text   :   > FLASH				/*The program code*/
    .const  :   > FLASH				/*All variables are stored here, some are copied into their respective sections by startup code*/
    .cinit  :   > FLASH
    .pinit  :   > FLASH
    .init_array : > FLASH

    .vtable :   > 0x20000000
    .data   :   > SRAM				/*Global and STATIC variables*/
    .bss    :   > SRAM				/*Global and STATIC variables*/
    .sysmem :   > SRAM				/*Dynamic memory allocation (Malloc, Calloc, etc..)*/
    .stack  :   > SRAM				/*Software system STACK*/
}

__STACK_TOP = __stack + 512;
