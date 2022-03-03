/* Entry Point */
ENTRY( Reset_Handler )

/* Memory layout */
MEMORY
{
    ram (xrw) : ORIGIN = 0x20000000, LENGTH = 40K
    rom (rx)  : ORIGIN = 0x08000000, LENGTH = 256K
}
INCLUDE cortex-m-generic.ld

