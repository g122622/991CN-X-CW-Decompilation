

<!-- ===== PDF 第 1-20 页 ===== -->

OKI SEMICONDUCTOR CO., LTD.

FEZ0317A0-U8-INST-02

# nX-U8/100 Core Instruction Manual

CMOS 8-bit microcontroller

## NOTICE

1. The information contained herein can change without notice owing to product and/or technical improvements. Before using the product, please make sure that the information being referred to is up-to-date.

2. The outline of action and examples for application circuits described herein have been chosen as an explanation for the standard action and performance of the product. When planning to use the product, please ensure that the external conditions are reflected in the actual circuit, assembly, and program designs.

3. When designing your product, please use our product below the specified maximum ratings and within the specified operating ranges including, but not limited to, operating voltage, power dissipation, and operating temperature.

4. OKI SEMICONDUCTOR assumes no responsibility or liability whatsoever for any failure or unusual or unexpected operation resulting from misuse, neglect, improper installation, repair, alteration or accident, improper handling, or unusual physical or electrical stress including, but not limited to, exposure to parameters beyond the specified maximum ratings or operation outside the specified operating range.

5. Neither indemnity against nor license of a third party’s industrial and intellectual property right, etc. is granted by us in connection with the use of the product and/or the information and drawings contained herein. No responsibility is assumed by us for any infringement of a third party’s right which may result from the use thereof.

6. The products listed in this document are intended for use in general electronics equipment for commercial applications (e.g., office automation, communication equipment, measurement equipment, consumer electronics, etc.). These products are not, unless specifically authorized by OKI SEMICONDUCTOR, authorized for use in any system or application that requires special or enhanced quality and reliability characteristics nor in any system or application where the failure of such system or application may result in the loss or damage of property, or death or injury to humans.

Such applications include, but are not limited to, traffic and automotive equipment, safety devices, aerospace equipment, nuclear power control, medical equipment, and life-support systems.

7. Certain products in this document may need government approval before they can be exported to particular countries. The purchaser assumes the responsibility of determining the legality of export of these products and will take appropriate and necessary steps at their own expense for these.

8. No part of the contents contained herein may be reprinted or reproduced without our prior permission.

## Contents

. Architecture 1-1   
1.1 Overview .......... ....... 1-1   
1.1.1 Features .. ....1-1   
1.2 CPU Resources and Programming Model ..... ......................................... 1-2   
1.2.1 Registers .. ............................... ......1-4   
1.2.1.1 General Registers ... .................................... ....1-5   
1.2.1.2 Base and Frame Pointers ................................................................... .....1-5   
1.2.2 Control Registers..... ...........................................................1-6   
1.2.2.1 Program Status Word (PSW).. ................................................................1-6   
1.2.2.2 Program Counter (PC) . ....1-8   
1.2.2.3 Code Segment Register (CSR).. ....1-8   
1.2.2.4 Link Registers (LR, ELR1, ELR2, and ELR3). ....1-9   
1.2.2.5 CSR Backup Registers (LCSR, ECSR1, ECSR2, and ECSR3)...............1-10   
1.2.2.6 PSW Backup Registers (EPSW1, EPSW2, and EPSW3).. ..... 1-11   
1.2.2.7 Stack Pointer (SP) . .... 1-11   
1.2.2.8 EA Register (EA)... .... 1-12   
1.2.2.9 Address Register (AR) . ................................ ....1-12   
1.2.2.10 Data Segment Register (DSR) ............................................................... 1-13   
1.3 Memory Spaces..... ............................................... 1-14   
1.3.1 Program/Code Memory Space... ................................................... ......1-14   
1.3.2 Vector Table .... .......1-15   
1.3.2.1 Reset Vectors . .... 1-15   
1.3.2.2 Interrupt Vectors ..... ................................................................. ..... 1-16   
1.3.2.3 Writing Vector Table . .......................................................... .... 1-17   
1.3.3 Program/Code Memory Space .....................................................................1-18   
1.3.4 DSR Prefix Instructions ..... ......................................................... .....1-18   
1.3.5 Data Memory Space.... ........................................................ .....1-19   
1.3.5.1 Data Types.. ............................................................... .... 1-20   
1.3.5.2 Address Assignment .. .............................................................. ..... 1-21   
1.3.5.3 Word Boundaries ........ .................................................................... ...... 1-21   
1.3.5.4 ROM Window... .......................................................... ...1-22   
1.3.6 Hardware Memory Models . .......................................................... .....1-22   
1.3.7 Interrupt Operation . ......................................................... ....1-24   
1.3.7.1 Interrupt Acceptance.... .............................................................. 1-24   
1.3.7.2 Nonmaskable Interrupts (NMI).. ... .................................................... .... 1-25   
1.3.7.3 Maskable Interrupts (MI) ... ......................................... ..... 1-26   
1.3.7.4 Software Interrupts (SWI) .. ....1-27   
1.4 Exception Levels and Backup Registers ................. ........ 1-28   
1.5 Interrupt Blocking ..... ........ 1-34   
1.6 Stack Modifications... ..... 1-35   
2. Addressing Types 2-1   
2.1 Addressing Types . ... 2-1   
2.2 Register Addressing .... .... 2-2   
2.3 Memory Addressing.. ... 2-3   
2.3.1 Register Indirect Addressing ... ......2-4   
2.3.2 Direct Addressing .. ....2-7   
2.4 Immediate Addressing.... .... 2-8   
2.5 Program/Code Memory Addressing . ... 2-9   
3. Instruction Descriptions 3-1   
3.1 Overview ...... ..... 3-1   
3.2 Instructions by Functional Group.... .... 3-2   
Arithmetic Instructions .. .......................... ............. .....3-2   
Shift Instructions ... ....................... ....3-2   
Load/Store Instructions . ............................................................. .....3-3   
Load/Store Instructions (cont.) .. ................................................................ ......3-4   
Load/Store Instructions (cont.) ..... ............................................................3-5   
Control Register Access Instructions ......................................................................3-6   
PUSH/POP Instructions.. ....3-6   
Coprocessor Data Transfer Instructions.. ....3-7   
Coprocessor Data Transfer Instructions (continued from previous page)...... ......3-8   
Bit Access Instructions . ....3-9   
PSW Access Instructions ...... ............................................................3-9   
Conditional Relative Branch Instructions.. ........................................... ....3-9   
Sign Extension Instruction... ............................ ....3-9   
Software Interrupt Instructions ....... ......... ................................................. ........3-10   
Branch Instructions.. ................................................... .......3-10   
Multiplication and Division Instructions.. ............................................. ......3-10   
Miscellaneous.. ............................................... ....3-10   
3.3 Instruction Execution Times .................................................................. 3-11   
3.4 Instruction Descriptions .... ..... 3-22   
ADD ERn , ERm ........................................................................................ ......3-23   
ADD ERn , #imm7 ..... ............................................................................... ....3-24   
ADD Rn , obj ........ ................................................................................ ......3-25   
ADD SP , #signed8 ...................................................................................... ......3-26   
ADDC Rn , obj .............................................................................................. .......3-27   
AND Rn , obj .... .................................................................................. .....3-28   
B Cadr ........ .........................................................................................................3-29   
B ERn ...................................................................................................................3-30   
Bcond Radr ...... .......................................................................................... .....3-31   
BL Cadr ................................................................................................................3-33   
BL ERn .................................................................................................................3-34   
BRK ...... ..................................................................................... .....3-35   
CMP ERn , ERm........................................................................................... ........3-36   
CMP Rn , obj ........................................................................................................3-37   
CMPC Rn , obj................................................................................................ ......3-38   
CPLC ........ .........................................................................................................3-39   
DAA Rn ................................................................................................................3-40   
DAS Rn ...... ................................................................................................. ........3-41   
DEC [EA] ...................................................................................................... ........3-42   
DI ...........................................................................................................................3-43   
DIV ERn , Rm ............................................................................................... .....3-44   
EI .......... ............................................................................................... .....3-45   
EXTBW ERn.... .......................................................................................... .....3-46   
INC [EA] ........ ............................................................................................... ........3-47   
L ERn, obj.... .......................................................................................... ....3-48   
L QRn,obj .... ....................................................................................... ......3-50   
L Rn, obj ...... ............................................................................................ ........3-51   
L XRn,obj....... .....................................................................................................3-53   
LEA obj ..... ..................................................................................... .......3-54   
MOV CERn , obj... ................................................................................. .....3-55   
MOV CQRn , obj...................................................................................................3-56   
MOV CRn , obj ..... ............................................................................. .....3-57   
MOV CRn , Rm.....................................................................................................3-58   
MOV CXRn , obj ...................................................................................................3-59   
MOV ECSR , Rm...... ................................................................................. .....3-60   
MOV ELR , ERm ..................................................................................................3-61   
MOV EPSW , Rm .................................................................................................3-62   
MOV ERn , ELR .... ................................................................................ ....3-63   
MOV ERn , ERm ..................................................................................................3-64   
MOV ERn , #imm7................................................................................................3-65   
MOV ERn , SP... ................................................................................... ....3-66   
MOV obj , CERm .......................................................................................... ......3-67   
MOV obj , CQRm...................................................................................... .......3-68   
MOV obj , CRm ........................................................................................... .....3-69   
MOV obj , CXRm .................................................................................... ......3-70   
MOV PSW , obj ....................................................................................................3-71   
MOV Rn , CRm............................................................................................... ......3-72   
MOV Rn , ECSR......................................................................................... .......3-73   
MOV Rn , EPSW ..... .................................................................................. .....3-74   
MOV Rn , PSW............................................................................................. .......3-75   
MOV Rn , obj ........................................................................................................3-76MOV SP , ERm.....................................................................................................3-77   
MUL ERn,Rm .......................................................................................................3-78   
NEG Rn ..... ................................................................................... ....3-79   
NOP...... ......................................................................................................3-80   
OR Rn , obj...........................................................................................................3-81   
POP register list ... ................................................................................... ....3-82   
POP obj ...... ......................................................................................... .......3-84   
PUSH register list .................................................................................................3-85   
PUSH obj...... ..................................................................................... .......3-87   
RB Dbitadr ...... ............................................................................................ .......3-88   
RB Rn . bit_offset .................................................................................................3-89   
RC ....... .......................................................................................... ......3-90   
RT..........................................................................................................................3-91RTI.........................................................................................................................3-92   
SB Dbitadr ............................................................................................................3-93   
SB Rn . bit_offset ........................................................................................... ......3-94   
SC ........... .................................................................................. ........3-95   
SLL Rn , obj................................................................................................. .........3-96   
SLLC Rn , obj ...... ....................................................................................... .....3-97   
SRA Rn , obj....... ................................................................................... .......3-98   
SRL Rn , obj .........................................................................................................3-99   
SRLC Rn , obj .............................................................................................. ......3-100   
ST ERn , obj ............................................................................................. .....3-101   
ST QRn , obj....... ....................................................................................... .....3-103   
ST Rn , obj ................................................................................................. ......3-104   
ST XRn , obj ...... .................................................................................... .....3-106   
SUB Rn , Rm ............................................................................................... .......3-107   
SUBC Rn , Rm .......................................................................................... .....3-108   
SWI #snum ...... .................................................................................. ....3-109   
TB Dbitadr ...... ..................................................................................... ....3-110   
TB Rn . bit_offset......................................................................................... .......3-111   
XOR Rn , obj .... ............................... .................... ....3-112

## 4. Appendix

Arithmetic Instructions .. .4-1   
Shift Instructions .. .4-1   
Load/Store Instructions . .4-2   
Control Register Access Instructions ..4-3   
PUSH/POP Instructions... ..4-3   
Coprocessor Data Transfer Instructions.. ..4-4   
EA Register Data Transfer Instructions.. .4-4   
ALU Instructions . ..4-4   
Bit Access Instructions . .4-5   
PSW Access Instructions . .4-5   
Conditional Relative Branch Instructions. ..4-5   
Sign Extension Instruction.. .4-6   
Software Interrupt Instructions . .4-6   
Branch Instructions.. .4-6   
Multiplication and Division Instructions.. ..4-6   
Miscellaneous... .4-6

## 1.1 Overview

## 1.1.1 Features

The U8 architecture has the following features.

## • Powerful Instruction Set

Instructions for data transfers, arithmetic, comparison, logic operations, bit manipulation, bitwise logic operations, branches, conditional branches, call/return stack manipulation, and arithmetic shifts

## • Variety of Addressing Modes

Register addressing

Register indirect addressing

Stack pointer addressing

Control register addressing

EA register indirect addressing

General-purpose register indirect addressing

Direct addressing

Register indirect bit addressing

Direct bit addressing

## • Memory Spaces

Program/code memory (ROM)

Up to 16 segments of 32 kilowords (0000H-FFFFH) each

Data memory (RAM)

Up to 256 segments of 64 kilobytes (0000H-FFFFH) each

## • Interrupts

Dedicated emulator interrupts

Nonmaskable interrupts

Maskable interrupts

Software interrupts

## 1.2 CPU Resources and Programming Model

The U8 architecture features two address spaces: 1 megabyte for code and 16 megabytes for data. Both address spaces are divided into physical segments of 64 kilobytes each. The memory configuration for physical segment #0 (0:0000H to 0:FFFFH) differs, however, from the others.

Physical segment #0 provides two sets of addresses and separate registers for accessing them: a 32-kiloword program/code memory segment accessed with the program counter (PC) and a 64-kilobyte data memory segment accessed with the address register (AR). If the address in AR is within the ROM window, however, the register accesses program/code memory, not the data memory.

Physical segments #1 and higher, with addresses above the first 64 kilobytes, form a single address space mixing program/code and data memory. Accessing a physical segment assigned to program/code memory requires a 20-bit address (CSR:PC) combining four bits from the code segment register (CSR) and 16 bits from program counter (PC); a physical segment assigned to data memory, a 24-bit address (DSR:AR) combining eight bits from the data segment register (DSR) and 16 bits from the address register (AR).

Figure 1.1 summarizes the layout of these U8 memory spaces.

<!-- image-->  
Figure 1.1. U8 Memory Spaces

## 1.2.1 Registers

General registers lie at the center of U8 hardware operation. Also shown in Figure 1.2 are the control registers.

<!-- image-->  
Figure 1.2. Register Set

## 1.2.1.1 General Registers

These 16 registers at the center of calculations are one byte wide. Special addressing modes, however, also group adjacent registers together to permit access as eight word-sized registers (ERn), four double word-sized registers (XRn), and two quad word-sized registers (QRn).

If an interrupt handler modifies the contents of these registers, it must explicitly save them with PUSH instructions at its entry point and restore them with POP instructions before returning.

<table><tr><td rowspan=8 colspan=1>QRO</td><td rowspan=4 colspan=1>XRO</td><td rowspan=2 colspan=1>ERO</td><td rowspan=1 colspan=1>R0</td><td rowspan=1 colspan=1></td></tr><tr><td rowspan=1 colspan=1>R1</td><td rowspan=1 colspan=1></td></tr><tr><td rowspan=2 colspan=1>ER2</td><td rowspan=1 colspan=1>R2</td><td rowspan=1 colspan=1></td></tr><tr><td rowspan=1 colspan=1>R3</td><td rowspan=1 colspan=1></td></tr><tr><td rowspan=4 colspan=1>XR4</td><td rowspan=2 colspan=1>ER4</td><td rowspan=1 colspan=1>R4</td><td rowspan=1 colspan=1></td></tr><tr><td rowspan=1 colspan=1>R5</td><td rowspan=1 colspan=1></td></tr><tr><td rowspan=2 colspan=1>ER6</td><td rowspan=1 colspan=1>R6</td><td rowspan=1 colspan=1></td></tr><tr><td rowspan=1 colspan=1>R7</td><td rowspan=1 colspan=1></td></tr><tr><td rowspan=8 colspan=1>QR8</td><td rowspan=4 colspan=1>XR8</td><td rowspan=2 colspan=1>ER8</td><td rowspan=1 colspan=1>R8</td><td rowspan=1 colspan=1></td></tr><tr><td rowspan=1 colspan=1>R9</td><td rowspan=1 colspan=1></td></tr><tr><td rowspan=2 colspan=1>ER10</td><td rowspan=1 colspan=1>R10</td><td rowspan=1 colspan=1></td></tr><tr><td rowspan=1 colspan=1>R11</td><td rowspan=1 colspan=1></td></tr><tr><td rowspan=4 colspan=1>XR12</td><td rowspan=2 colspan=1>ER12</td><td rowspan=1 colspan=1>R12</td><td rowspan=1 colspan=1>BP(Lower byte)</td></tr><tr><td rowspan=1 colspan=1>R13</td><td rowspan=1 colspan=1>BP(Upper byte)</td></tr><tr><td rowspan=2 colspan=1>ER14</td><td rowspan=1 colspan=1>R14</td><td rowspan=1 colspan=1>FP(Lowerbyte)</td></tr><tr><td rowspan=1 colspan=1>R15</td><td rowspan=1 colspan=1>FP(Upperbyte)</td></tr></table>

Figure 1.3. General Registers

## Examples: Using general registers

<table><tr><td>MOV </td><td>R0，#7</td><td></td><td>; byte-sized register</td></tr><tr><td>L</td><td></td><td></td><td>ER0,[EA+] ; word-sized register</td></tr><tr><td>L</td><td></td><td>XR0,[EA] </td><td> ; double word-sized register</td></tr><tr><td>ST</td><td></td><td>QRO,[EA]</td><td>; quad word-sized register</td></tr><tr><td>SB</td><td>R3.2</td><td></td><td>; individual bit in register</td></tr></table>

## 1.2.1.2 Base and Frame Pointers

The C compiler uses two global pointers. It uses ER12 as the base pointer (BP) and ER14 as the frame pointer (FP). These two registers therefore offer special addressing modes in addition to their roles as general registers. For further details, see Chapter 2.

## 1.2.2 Control Registers

These registers control program flow and hold operational status information. There are 18 such registers, each with its own special function. The contents of the entire group is sometimes referred to as the program context.

## 1.2.2.1 Program Status Word (PSW)

<table><tr><td></td><td>7 6</td><td></td><td>5</td><td>4</td><td>3</td><td>2</td><td>1 0</td></tr><tr><td>PSW</td><td>C</td><td>Z</td><td>S</td><td>OV</td><td>MIE</td><td>HC</td><td>ELEVEL</td></tr></table>

This 8-bit register contains five flags tracking the results of instruction execution, one control bit, and one field.

The hardware automatically saves these contents to an exception program status word (EPSW) register when it accepts an interrupt request. The RTI instruction at the end of the interrupt handler restores them.

This register contains five flags tracking the results of arithmetic instruction execution, one bit controlling interrupt acceptance, and a 2-bit field indicating the exception level (ELEVEL). The program can change these contents at any time. After a reset, they are all zero.

These flags, bit, and field have the following functions.

• Bit 7: Carry flag (C)

This bit goes to “1” if an arithmetic, shift, or comparison instruction produces a carry out of bit 7 or bit 0 or a borrow into bit 7. Otherwise, it goes to “0.”

The contents can also be directly set, reset, and inverted with the SC, RC, or CPLC instructions and tested with the conditional branch instructions.

• Bit 6: Zero flag (Z)

This bit goes to “1” if an arithmetic or data transfer instruction produces a zero result. Otherwise, it goes to “0.”

The contents can be tested with the conditional branch instructions.

• Bit 5: Sign flag (S)

This bit tracks the sign bit in the result from an arithmetic, comparison, or bitwise logical instruction: “1” for negative, “0” for positive.

• Bit 4: Overflow flag (OV)

This bit goes to “1” if a signed arithmetic instruction produces a carry out of or a borrow into bit 7—that is, a result that does not fit into the twos complement range available. Otherwise, it

goes to “0.”

• Bit 3: Master interrupt enable bit (MIE)

This bit is a mask controlling the acceptance of maskable interrupt requests. Setting it to “1” enables such interrupt requests; “0” disables them.

The hardware automatically sets this bit to “0” when it accepts a maskable interrupt request. The contents can also be directly set or reset with the EI and DI instructions.

• Bit 2: Half carry flag (HC)

This bit, used in BCD arithmetic, goes to “1” if an arithmetic or comparison instruction produces a carry out of or a borrow into bit 3 or bit 11. Otherwise, it goes to “0.”

• Bits 1 and 0: Exception level (ELEVEL)

This field gives the current exception level, an integer between 0 and 3 indicating the interrupt priority. The higher this number, the greater the priority. For a list of interrupts and their exception/priority levels, see Section 1.3.7 “Interrupt Operation.”

The U8 hardware accepts an interrupt request only if its interrupt priority is the same or greater than the current exception level (ELEVEL) setting.

## 1.2.2.1.1 Instructions Modifying PSW Flags

For further details on instructions modifying PSW flags and the exact nature of those modifications, see Section 3.2 “Instructions by Functional Group” and Chapter 4 “Appendix.”

## 1.2.2.2 Program Counter (PC)

<table><tr><td rowspan=1 colspan=15>1514131211109876543210</td><td rowspan=1 colspan=1>654321</td></tr><tr><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td></tr></table>

This 16-bit register holds the offset portion of the address of the next instruction to be executed. The hardware automatically increments it immediately after fetching an instruction from program/code memory, creating the cycle necessary for sequential execution. Branch and other instructions, however, break this cycle by overwriting this default with a different address.

Instructions always start on word boundaries, so the hardware increments the program counter (PC) by two each time and forces the lowest bit in any address loaded to “0” to enforce this alignment.

After a reset, the program counter (PC) starts with the contents of the vector corresponding to the reset factor.

When the hardware accepts an interrupt request, it automatically saves the contents of this register for use as part of the return address in the exception link register (ELR1 to ELR3) for the current exception level (ELEVEL) setting. The RTI instruction at the end of the interrupt handler restores them.

## 1.2.2.3 Code Segment Register (CSR)

<table><tr><td></td><td>3</td><td>2</td><td>1</td><td>0</td></tr><tr><td>CSR</td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td></tr></table>

This 4-bit register holds the physical segment number (0 to 15) portion of the address for the current instruction. The remaining 16 bits (0 to FFFFH), representing an offset within that physical segment, come from the program counter (PC). Together, these two registers specify a 20-bit address (CSR:PC) accessing the entire program/code memory space.

Address calculations apply only to the 16-bit offset, ignoring any over- or underflow, so never modify the CSR contents. The same applies to PC overflow. Program execution thus continuously cycles through the addresses in the same physical segment until the program explicitly overwrites the CSR contents.

The following actions modify the CSR contents.

• interrupt acceptance: CSR goes to zero.

• reset : CSR goes to zero.

• B Cadr instruction: CSR goes to the value specified in the instruction.

• BL Cadr instruction: CSR goes to the value specified in the instruction.

• RTI instruction: CSR goes to the value from the ECSR register corresponding to the current

exception level (ELEVEL) setting from program status word (PSW).

• RT instruction: CSR goes to the value from the LCSR register.

• POP PC instruction: CSR goes to the value from the stack.

When the hardware accepts an interrupt request, it automatically saves the contents of this register for use as part of the return address in the ECSR register (ECSR1 to ECSR3) for the current exception level (ELEVEL) setting. The RTI instruction at the end of the interrupt handler restores them.

After a reset, this register contains zero.

## 1.2.2.4 Link Registers (LR, ELR1, ELR2, and ELR3)

<table><tr><td></td><td></td><td>1514131211109876543210</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td>LR</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td rowspan="3">ELR1</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td rowspan="2">ELR2</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td rowspan="2">ELR3</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr></table>

These four 16-bit registers are for saving the contents of the program counter (PC) during subroutines (LR) and interrupt handlers (ELR1 to ELR3). The lowest bit is always “0.”

The LR register holds the offset portion of the return address for a subroutine called with a BL instruction. The RT instruction at the end of the subroutine loads the LR contents back into the program counter (PC). Note that the program has a choice of two instructions for returning from a subroutine to its caller: RT or POP. For further details, see Section 1.4 “Exception Levels and Backup Registers.”

The registers ELR1 to ELR3 hold the offset portions of the return addresses for interrupt handlers at the corresponding exception levels. The hardware saves the return address using the index number assigned to the interrupt being accepted. For a list of interrupts and their exception/priority levels, see Section 1.3.7 “Interrupt Operation.”

Note that modifying the ELEVEL portion of the program status word (PSW) in software requires particular care because it changes the index pointing to the most recently used ELR-ECSR register pair.

Note also that the ELR3-ECSR3 register pair is only physically present in models including the on-chip debugger. Accessing these registers on other models leads to unpredictable operation. Always check the User’s Manual for the target device first.

## 1.2.2.5 CSR Backup Registers (LCSR, ECSR1, ECSR2, and ECSR3)

<!-- image-->

These four 4-bit registers are for saving the contents of the code segment register (CSR) during subroutines (LCSR) and interrupt handlers (ECSR1 to ECSR3).

The LCSR register holds the physical segment portion of the return address for a subroutine called with a BL instruction. The RT instruction at the end of the subroutine loads the LCSR contents back into the code segment register (CSR).

Note that the program has a choice of two instructions for returning from a subroutine to its caller: RT or POP. For further details, see Section 1.4 “Exception Levels and Backup Registers.”

The registers ECSR1 to ECSR3 hold the physical segment portions of the return addresses for interrupt handlers at the corresponding exception levels. The hardware saves the return address using the index number assigned to the interrupt being accepted. For a list of interrupts and their exception/priority levels, see Section 1.3.7 “Interrupt Operation.”

Note that modifying the ELEVEL portion of the program status word (PSW) in software requires particular care because it changes the index pointing to the most recently used ELR-ECSR register pair.

Note also that the ELR3-ECSR3 register pair is only physically present in models including the on-chip debugger. Accessing these registers on other models leads to unpredictable operation. Always check the User’s Manual for the target device first.

<!-- ===== PDF 第 21-40 页 ===== -->

## 1.2.2.6 PSW Backup Registers (EPSW1, EPSW2, and EPSW3)

<table><tr><td></td><td></td><td></td><td></td><td></td><td>76543210</td><td></td><td>0</td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr></table>

These three 8-bit registers are for saving the contents of the program status word (PSW) during interrupt handlers.

The hardware saves the program status word (PSW) using the index number assigned to the interrupt being accepted. For a list of interrupts and their exception/priority levels, see Section 1.3.7 “Interrupt Operation.”

Note that modifying the ELEVEL portion of the program status word (PSW) in software requires particular care because it changes the index pointing to the most recently used EPSW register.

Note also that the EPSW3 register is only physically present in models including the on-chip debugger. Accessing this register on other models leads to unpredictable operation. Always check the User’s Manual for the target device first.

## 1.2.2.7 Stack Pointer (SP)

<table><tr><td rowspan=1 colspan=16>1514131211109876543210</td></tr><tr><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td></tr></table>

This 16-bit register holds a pointer to the start of the stack for saving and restoring the contents of registers—with the PUSH and POP instructions, for example.

Stack operations are always word sized. One saving word-sized data to the stack subtracts 2 from this register and then copies the data to that new address. Restoring data copies a word from the stack to the specified destination and then adds 2 to this register.

There is no automatic word alignment. If the contents of this register are odd, that address is used as is.

This register is an independent one, fully accessible from programs with the appropriate instructions—PUSH and POP, for example.

After a reset, this register contains the contents of addresses 0000H and 0001H in the program/code memory in its lower and upper bytes, respectively.

## 1.2.2.8 EA Register (EA)

<table><tr><td rowspan=1 colspan=7>151413121110987654321（</td><td rowspan=1 colspan=1>8</td><td rowspan=1 colspan=1>7</td><td rowspan=1 colspan=1>6</td><td rowspan=1 colspan=1>5</td><td rowspan=1 colspan=4>4321</td><td rowspan=1 colspan=1>0</td></tr><tr><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td></tr></table>

This 16-bit register holds an address for use by instructions that access data memory indirectly via this register.

These 16 bits are sufficient for accessing data memory addresses in physical segment #0. Accessing physical segments #1 and higher, however, requires prefixing this offset with the contents of the data segment register (DSR), described below, to form a 24-bit address (DSR:EA).

This register is accessible from programs with the LEA instruction for loading it and with the stack manipulation instructions PUSH and POP.

## 1.2.2.9 Address Register (AR)

<table><tr><td rowspan=2 colspan=5>1514131211</td><td rowspan=2 colspan=12>1514131211109876543210</td></tr><tr><td rowspan=1 colspan=1></td></tr><tr><td rowspan=3 colspan=1></td><td rowspan=3 colspan=1></td><td rowspan=3 colspan=1></td><td rowspan=3 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=2></td><td rowspan=1 colspan=1></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td rowspan=2 colspan=1></td><td rowspan=2 colspan=2></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1></td></tr></table>

This 16-bit register temporarily holds an address for use by instructions accessing data memory. It is for the exclusive use by the U8 core, so is not accessible from programs.

## 1.2.2.10 Data Segment Register (DSR)

DSR

<table><tr><td rowspan=1 colspan=3>765</td><td rowspan=1 colspan=1>4</td><td rowspan=1 colspan=1>3</td><td rowspan=1 colspan=1>2</td><td rowspan=1 colspan=1>10</td></tr><tr><td rowspan=3 colspan=1></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td rowspan=2 colspan=1></td><td rowspan=2 colspan=1></td><td rowspan=2 colspan=1></td><td rowspan=2 colspan=1></td><td rowspan=2 colspan=1></td><td></td></tr><tr><td rowspan=1 colspan=1></td></tr></table>

This 8-bit register holds a physical segment number for accessing data memory in physical segments #1 and higher. This number can be anywhere between 0 and 255.

Accessing addresses within the specified physical segment uses the 16-bit offset (0 to FFFFH) in the EA address—that is, a 24-bit address with the contents of this register in the top eight bits and the contents of the EA register in the lower 16 bits.

Memory access instructions specifying a numeric value for the physical segment first update DSR to this new value. Those with the notation DSR in that position use the current contents of this register. In the absence of either notation, the instruction always ignores the DSR contents and uses physical segment #0.

The following code fragment gives some examples of data memory access.
<table><tr><td>L</td><td>R0</td><td>,5:1234H</td><td></td><td>Set DSR to 5 and load R0 from 5:1234H，an address in physical segments #1 and higher.</td></tr><tr><td>LEA</td><td></td><td>55AAH</td><td></td><td></td></tr><tr><td>ST</td><td>R0</td><td>,3:[EA+]</td><td></td><td>Set DSR to 3 and store the contents of R0 in 3:55AAH,an</td></tr><tr><td></td><td></td><td></td><td></td><td>address in physical segments #1 and higher. Increment EA.</td></tr><tr><td>ST</td><td>R1</td><td>,3:[EA+]</td><td></td><td>Set DSR to 3 and store the contents of R1 in 3:55ABH,an address in physical segments #1 and higher.</td></tr><tr><td></td><td></td><td></td><td></td><td>Increment EA.</td></tr><tr><td>ST</td><td>R2</td><td>,3:[EA+]</td><td></td><td>Set DSR to 3 and store the contents of R2 in 3:55ACH,an address in physical segments #1 and higher.</td></tr><tr><td></td><td></td><td></td><td></td><td>Increment EA.</td></tr><tr><td>L</td><td>R0</td><td>,5:1234H</td><td></td><td>Set DSR to 5 and load R0 from 5:1234H，an address in</td></tr><tr><td></td><td></td><td></td><td></td><td>physical segments #1 and higher.</td></tr><tr><td>L</td><td>R1</td><td>,1234H</td><td></td><td>Load R1 from offset 1234H in data memory physical segment #0.</td></tr><tr><td>L</td><td>R2</td><td>,01235H</td><td></td><td>Set DSR to O and load R2 from offset 1235H in data memory physical segment #0.</td></tr><tr><td></td><td></td><td></td><td></td><td></td></tr><tr><td>LEA L</td><td>AA55H</td><td>R5,DSR: [EA+]</td><td></td><td>Load R5 from the physical segment currently in DSR using the</td></tr><tr><td></td><td></td><td></td><td></td><td>offset in EA (AA55H).</td></tr><tr><td></td><td></td><td></td><td></td><td>Increment EA.</td></tr><tr><td>L</td><td></td><td>R6,DSR:[EA+]</td><td></td><td>Load R6 from the physical segment currently in DSR using the</td></tr><tr><td></td><td></td><td></td><td></td><td>offset in EA (AA56H).</td></tr></table>

After a reset, this register contains zero.

## 1.3 Memory Spaces

The U8 memory space consists of 256 physical segments of 64K bytes each. It is shared by a 1-megabyte program/code memory space (0:0000H to F:FFFFH) and a 16-megabyte data memory space (0:0000H to FF:FFFFH). Physical segment #0, however, has a different structure from the others, #1 and higher.

## 1.3.1 Program/Code Memory Space

The U8’s 1-megabyte program/code memory space features 16 physical segments with 32 kilowords each. Its primary uses are holding the machine code necessary for program execution and read-only data tables. Programs access this space with 20-bit addresses (CSR:PC) combining the contents of the code segment register (CSR) in the top four bits and those of the program counter (PC) in the remaining 16 bits. The contents of the code segment register (CSR) are called the code segment.

Such address calculations as incrementing the program counter (PC) and adding or subtracting a displacement to calculate a relative branch target ignore any over- or underflow, so never modify the CSR contents.

The ROM window, a special region in physical segment #0, is accessible using RAM addressing.

Access with a physical segment uses a 16-bit offset between 0 and 0FFFEH. Address calculations affect only this 16-bit offset and ignore any over- or underflow.

The following illustrates the layout of this memory space.

<!-- image-->

## 1.3.2 Vector Table

Addresses 0:0H to 0:0FEH in the program/code memory space are reserved for a vector table containing 16-bit offsets to the routines processing resets and interrupts. Each vector in the table starts at an even address. The hardware automatically resets the code segment register (CSR) to zero, so these routines must always start in physical segment #0.

<!-- image-->  
Figure 1.4. Vector Table

## 1.3.2.1 Reset Vectors

This portion of the vector table holds the entry points for processing resets—that is, the initial value for the stack pointer at address 0 and the reset routine entry points at addresses 2 and 4.

<!-- image-->  
Figure 1.5. Reset Vectors

## 1.3.2.2 Interrupt Vectors

## 1.3.2.2.1 Hardware Interrupt Vectors

This portion of the vector table holds the entry points for processing hardware interrupts. There are two nonmaskable interrupt requests, NMICE and NMI, plus room for up to 59 maskable ones.

<!-- image-->  
Figure 1.6. Hardware Interrupt Vectors

## 1.3.2.2.2 Software Interrupt Vectors

This portion of the vector table holds the entry points for interrupt requests from SWI instructions in the program.

<!-- image-->  
Figure 1.7. Software Interrupt Vectors

## 1.3.2.3 Writing Vector Table

In assembly language, use DW directives with labels representing the entry points as their operands as shown in the following code fragment.

Note that only the reset vectors must always be present. If the program does not use these interrupts, this region is available for normal program code.

```asm
;reset vector table
;
cseg at 0000h
dw spinit ; Initial value for stack pointer
dw start ; Initial value for program counter
dw brk ; Reset routine entry point for BRK instruction
org 0008h
dw nmi_entry ; Nonmaskable interrupt
dw Int1_entry ; Maskable interrupt #0
dw Int2_entry ; Maskable interrupt #1
:
:
;software interrupts
;
cseg at 0080h
swi_0: dw sw0_entry ; Software interrupt #0
swi_1: dw sw1_entry ; Software interrupt #1
:
:
;
;start of main procedure
;
start: ; Program entry point
```

## 1.3.3 Program/Code Memory Space

From the programming standpoint, there is no logical difference between physical segment #0 and the others. The linker and other tools automatically assign the program code to onboard memory available on the chip and then to external memory.

## 1.3.4 DSR Prefix Instructions

The U8 architecture divides memory spaces into physical segments of 64K bytes each, so accessing data in a physical segment other than physical segment #0 requires manipulating the data segment register (DSR) with one of the following three DSR prefix instructions.

<table><tr><td>DSR Prefix Instruction</td><td>Function</td></tr><tr><td>lll0_00ll_iiii_iiii</td><td>Load DSR with the 8-bit immediate value iii_iiii.</td></tr><tr><td>1001_00oo_dddd_1111</td><td>Load DSR with the contents of the general register Rd.</td></tr><tr><td>ll1l_1110_l00l_1111</td><td>Use the current DSR value.</td></tr></table>

DSR prefix instructions have this prefixing effect only when they immediately precede a memory access instruction. Memory access instructions without an immediately preceding DSR prefix instruction access physical segment #0.

The hardware automatically disables all interrupts between a DSR prefix instruction and the immediately following instruction. For further details, see Section 1.5 “Interrupt Blocking” below.

Note: To prevent unintended operation and provide the strongest checking possible of memory access, the U8 assembly language specifications deliberately forbid the use of the DSR prefix instructions in program source code. Instead, use the corresponding DSR prefix inside the memory access instruction itself. For further details, see Section 2.3 “Memory Addressing” below.

## 1.3.5 Data Memory Space

The U8’s 16-megabyte data memory space features 256 physical segments with 64 kilobytes each. Its primary use is holding data that is written as well as read.

Programs access this space with 24-bit addresses (DSR:AR) combining the contents of the data segment register (DSR) in the top eight bits and those of the address register (AR) in the remaining 16 bits. The contents of the data segment register (DSR) are called the data segment.

Physical segment #0 consists of the ROM window plus one or two data regions. The ROM window is a special region accessing program/code memory addresses using RAM addressing. The corresponding data memory addresses are not physically present. The primary use for this window is accessing table data in ROM.

The following illustrates the layout of this memory space.  
<!-- image-->

## 1.3.5.1 Data Types

This Section describes the data types supported by U8 instructions.

## Unsigned Byte

This data type is used by instructions operating on bytes. Values range from 0 to 255. Arithmetic operations that underflow or overflow this range set the carry flag (C) to “1” and discard all but the lowest eight bits to produce a result modulo 256.

Bit operations manipulate individual bits. The bits are numbered 0 to 7 from the least significant bit (LSB) to the most significant bit (MSB).

## Signed Byte

This data type is used by instructions operating on bytes. The top bit is considered the sign bit, producing twos complement values ranging from -128 to +127. Arithmetic operations that underflow or overflow this range set the overflow flag (OV) to “1.”

## Unsigned Word

This data type is used by instructions operating on words. Values range from 0 to 65,535. Arithmetic operations that underflow or overflow this range set the carry flag (C) to “1” and discard all but the lowest 16 bits to produce a result modulo 65,536.

Memory storage is little endian, with the lower byte (bits 7 to 0) preceding the upper (bits 15 to 8). Data memory requires word boundary alignment with the lower byte at an even address and the upper at the next, odd address. Program/code memory does not impose this restriction. The address of word data is always the address of its lower byte.

Bitwise operations manipulate individual bits. The bits are numbered 0 to 15 from the least significant bit (LSB) to the most significant bit (MSB).

## Signed Word

This data type is used by instructions operating on words. The top bit is considered the sign bit, producing twos complement values ranging from -32768 to + 32767. Arithmetic operations that underflow or overflow this range set the overflow flag (OV) to “1.”

Memory storage is little endian, with the lower byte (bits 7 to 0) preceding the upper (bits 15 to 8). Data memory requires word boundary alignment with the lower byte at an even address and the upper at the next, odd address. Program/code memory does not impose this restriction. The address of word data is always the address of its lower byte.

## Bit

This data type is used by instructions operating on bits. The only values are “0” and “1.” This type applies to individual bits in most registers and all bits in memory. Bit addressing uses the name of a byte-sized register or a memory address plus, the dot operator, and the number (0 to 7). The operations available for these bits include transfers, logical operations, and bit test and jump.

## 1.3.5.2 Address Assignment

Memory addresses are in bytes. Byte addressing assigns a unique address to every byte in memory. These addresses run from 0 to FFFFH (65,535) in each 64-kilobyte physical segment.

The U8 architecture separates memory into program/code memory and data memory, each with their own set of byte addresses.

## 1.3.5.3 Word Boundaries

The U8 data memory has word boundaries. The hardware automatically enforces word alignment by ignoring the lowest bit in the address, forcing it to “0.” Instructions accessing word-, double word-, or quad word-sized data using odd-numbered therefore access the preceding even-numbered address without triggering an addressing error. The programmer must, therefore, assign these larger data types to word boundaries. Note that there are no additional boundaries for multiword types. The only requirement is that they be on word boundaries.

Program/code memory also has word boundaries. So too does program/code memory accessed by the ROM window.

<!-- image-->  
Figure 1.8. Word Boundaries in Memory

## 1.3.5.4 ROM Window

This window, assigned to an unused portion of physical segment #0 in data memory, is for accessing the corresponding program/code memory addresses with RAM addressing. The U8 architecture thus does not need special instructions for accessing data in program/code memory (ROM). Using a RAM access instruction with an address in the ROM window produces the same result.

Accessing an address in the ROM window takes, however, more instruction cycles than the same instruction accessing data memory. For further details, see Section 3.3 “Instruction Execution Times.”

The ROM window supports only read access. Writing to a ROM window address does not produce meaningful results.

## 1.3.6 Hardware Memory Models

The U8 architecture provides hardware control over the number of physical segments accessible as program/code memory: 64 kilobytes (32 kilowords) or 1 megabyte (512 kilowords). The procedure for specifying this hardware memory model is in the User’s Manual for the target device.

The following Table summarizes the models available.

<table><tr><td rowspan=1 colspan=1>Model Name</td><td rowspan=1 colspan=1>Program/Code Addresses</td><td rowspan=1 colspan=1>CSRCSR BackupRegisters</td></tr><tr><td rowspan=1 colspan=1>SMALL</td><td rowspan=1 colspan=1>Program memory: 0H - FFFFHData memory: 0H -FF:FFFFH</td><td rowspan=1 colspan=1>Not used</td></tr><tr><td rowspan=1 colspan=1>LARGE</td><td rowspan=1 colspan=1>Program memory: OH -F:FFFFHDatamemory: OH-FF:FFFFH</td><td rowspan=1 colspan=1>Used</td></tr></table>

The choice of hardware memory model affects the following aspects of operation.

• Amount of program/code memory available

• Operation of subroutine calls and corresponding RT instructions

• Operation of interrupts and corresponding RTI instructions

• Operation of PUSH and POP instructions

The following Table outlines these differences in more detail.
<table><tr><td rowspan=1 colspan=1></td><td rowspan=1 colspan=1>SMALL</td><td rowspan=1 colspan=1>LARGE</td></tr><tr><td rowspan=1 colspan=1>Amount of program/code memory available</td><td rowspan=1 colspan=1>64K bytes(0H - 0FFFFH)</td><td rowspan=1 colspan=1>1M bytes(0H - F:FFFFH)</td></tr><tr><td rowspan=1 colspan=1>Registers saved during subroutine call</td><td rowspan=1 colspan=1>PC</td><td rowspan=1 colspan=1>PCCSR</td></tr><tr><td rowspan=1 colspan=1>Registers restored by RT instruction</td><td rowspan=1 colspan=1>PC</td><td rowspan=1 colspan=1>PCCSR</td></tr><tr><td rowspan=1 colspan=1>Registers saved during interrupt acceptance</td><td rowspan=1 colspan=1>PCPSW</td><td rowspan=1 colspan=1>PCPSWCSR</td></tr><tr><td rowspan=1 colspan=1>Registers restored by RTI instruction</td><td rowspan=1 colspan=1>PCPSW</td><td rowspan=1 colspan=1>PCPSWCSR</td></tr><tr><td rowspan=2 colspan=1>Registers saved by PUSH LR/ELRinstruction</td><td rowspan=1 colspan=1>LR</td><td rowspan=1 colspan=1>LRLCSR</td></tr><tr><td rowspan=1 colspan=1>ELR</td><td rowspan=1 colspan=1>ELRECSR</td></tr><tr><td rowspan=2 colspan=1>Registers restored by POP LR/PC instruction</td><td rowspan=1 colspan=1>LR</td><td rowspan=1 colspan=1>LRLCSR</td></tr><tr><td rowspan=1 colspan=1>PC</td><td rowspan=1 colspan=1>PCCSR</td></tr></table>

## 1.3.7 Interrupt Operation

## 1.3.7.1 Interrupt Acceptance

The U8 hardware accepts an interrupt request (NMICE, NMI, or MI) only if its interrupt level is the same or greater than the current exception level (ELEVEL) setting.

The following Table lists the interrupt level, an integer between 0 and 3 indicating the interrupt priority, for each type of interrupt.

<table><tr><td>Interrupt Type</td><td>Interrupt Level</td></tr><tr><td>Emulator interrupt (NMICE)*1</td><td>3</td></tr><tr><td>Nonmaskable interrupt (NMI)</td><td>2</td></tr><tr><td>Software interrupt (SWI)</td><td>1</td></tr><tr><td>Maskable interrupt (Ml)</td><td>1</td></tr></table>

\*1 This interrupt request requires an in-circuit emulator. It is not available to user application programs.

An exception level (ELEVEL) setting of zero indicates that there are no interrupt requests pending.

The higher the interrupt level, the greater the priority.

When the hardware accepts an interrupt request, it saves the interrupt level in the ELEVEL field of the program status word (PSW).

When the U8 hardware receives an interrupt request, it first compares the interrupt level with the current exception level (ELEVEL) setting. If the interrupt level is the same or greater than ELEVEL, the hardware loads the program counter (PC) from the appropriate entry in the vector table.

<table><tr><td>Address in vector table</td><td>Description</td></tr><tr><td>0000H</td><td>Initial value for stack pointer</td></tr><tr><td>0002H</td><td>Reset routine entry point for external reset input or BRK instruction with exception level (ELEVEL) setting of 2 or 3</td></tr><tr><td>0004H</td><td>Reset routine_entry_point for BRK instruction with exception level (ELEVEL) setting of 0 or 1</td></tr><tr><td>0006H</td><td>Interrupt handler entry point for emulator interrupt (NMICE)</td></tr><tr><td>0008H- 007EH</td><td>Interrupt handler entry points for nonmaskable (NMl) and maskable (MI) interrupts</td></tr><tr><td>0080H-00FEH</td><td>Interrupt handler entry points for software interrupts (SWl)</td></tr></table>

The following gives the detailed acceptance procedure for each interrupt type.

## 1.3.7.2 Nonmaskable Interrupts (NMI)

User application programs have no means of masking nonmaskable interrupts. When the hardware detects one, control immediately transfers to the appropriate NMI interrupt handler. If the CPU is already executing the NMI interrupt handler, control still returns to the beginning.

The hardware masks them, however, in the following situations.

• Between a reset (either hardware reset input or a BRK instruction with an ELEVEL setting of 3) and the end of the first instruction in the reset handler

• Between the start of the interrupt acceptance cycle and the end of the first instruction in the interrupt handler

• Between a DSR prefix instruction and the immediately following instruction

A nonmaskable interrupt request automatically causes the hardware to perform the following actions.

1. Save PC in ELR2.

2. Save CSR in ECSR2.

3. Save PSW in EPSW2.

4. Set ELEVEL field in PSW to 2.

5. Reset CSR to zero.

6. Load program counter (PC) from vector table.

7. Disable interrupt requests for the duration of the first instruction in the interrupt handler.

The processing time required for the above actions is 3 cycles, however, when the interruption occurs immediately after the instruction using [EA+] addressing, the interruption sequence is started after one machine cycle of wait cycles is performed. For further details, see Section 3.3 “Instruction Execution Times.”

The NMI interrupt handler can exit in different ways. For further details, see Section 1.4 “Exception Levels and Backup Registers.”

## 1.3.7.3 Maskable Interrupts (MI)

Maskable interrupts have many sources among the onboard peripherals and external input pins. The hardware only accepts them, however, if the MIE bit in the program status word (PSW) is “1.”

The hardware masks them, however, in the following situations.

• Between a reset (either hardware reset input or a BRK instruction with an ELEVEL setting of 3) and the end of the first instruction in the reset handler

• Between the start of the interrupt acceptance cycle and the end of the first instruction in the interrupt handler

• Between a DSR prefix instruction and the immediately following instruction

• While the ELEVEL setting is 2 or 3

Acceptance of a maskable interrupt request automatically causes the hardware to perform the following actions.

1. Save PC in ELR1.

2. Save CSR in ECSR1.

3. Save PSW in EPSW1.

4. Set ELEVEL field in PSW to 1.

5. Set MIE bit in PSW to “0” to disable further interrupt requests.

6. Reset CSR to zero.

7. Load program counter (PC) from vector table.

8. Disable all interrupt requests for the duration of the first instruction in the interrupt handler.

The processing time required for the above actions is 3 cycles, however, when the interruption occurs immediately after the instruction using [EA+] addressing, the interruption sequence is started after one machine cycle of wait cycles is performed. For further details, see Section 3.3 “Instruction Execution Times.”

The MI interrupt handler can exit in different ways. For further details, see Section 1.4 “Exception Levels and Backup Registers.”

## 1.3.7.4 Software Interrupts (SWI)

Software interrupts come from inside the user application program, so are immediately accepted. The operand to the SWI instruction specifies the interrupt number.

A software interrupt request automatically causes the hardware to perform the following actions.

1. Save PC in ELR1.

2. Save CSR in ECSR1.

3. Save PSW in EPSW1.

4. Set ELEVEL field in PSW to 1.

5. Set MIE bit in PSW to “0” to disable further interrupt requests.

6. Reset CSR to zero.

7. Load program counter (PC) from vector table.

8. Disable all interrupt requests for the duration of the first instruction in the interrupt handler.

The processing time required for the above actions is 3 cycles, however, when the SWI instruction is executed immediately after the instruction using [EA+] addressing, the interruption sequence is started after one machine cycle of wait cycles is performed. For further details, see Section 3.3 “Instruction Execution Times.”

The software interrupt handler can exit in different ways. For further details, see Section 1.4 “Exception Levels and Backup Registers.”

## 1.4 Exception Levels and Backup Registers

The U8 architecture provides three sets of backup registers for saving the contents of the program counter (PC), code segment register (CSR), and program status word (PSW) during subroutine calls and interrupt handlers. The PC and CSR backup registers apply to both situations; the PSW ones, only to interrupt handlers.

The following Table summarizes the use of these backup registers.

PC Backup Registers
<table><tr><td rowspan=1 colspan=1>Name</td><td rowspan=1 colspan=1>Description</td></tr><tr><td rowspan=1 colspan=1>LR</td><td rowspan=1 colspan=1>This holds the offset portion of the return address for a subroutine call withthe BL instruction.</td></tr><tr><td rowspan=1 colspan=1>ELR1</td><td rowspan=1 colspan=1>This holds the offset portion of the return address for a maskable interrupt ora SWI instruction.</td></tr><tr><td rowspan=1 colspan=1>ELR2</td><td rowspan=1 colspan=1>This holds the offset portion of the return address for a nonmaskableinterrupt.</td></tr><tr><td rowspan=1 colspan=1>ELR3</td><td rowspan=1 colspan=1>This holds the ofset portion of the return address for an emulator interrupt.</td></tr></table>

CSR Backup Registers
<table><tr><td rowspan=1 colspan=1>Name</td><td rowspan=1 colspan=1>Description</td></tr><tr><td rowspan=1 colspan=1>LCSR</td><td rowspan=1 colspan=1>This holds the physical segment portion of the return address for asubroutine call with the BL instruction.</td></tr><tr><td rowspan=1 colspan=1>ECSR1</td><td rowspan=1 colspan=1>This holds the physical segment portion of the return address for a maskableinterrupt ora SWl instruction.</td></tr><tr><td rowspan=1 colspan=1>ECSR2</td><td rowspan=1 colspan=1>This holds the physical segment portion of the return address for anonmaskable interrupt.</td></tr><tr><td rowspan=1 colspan=1>ECSR3</td><td rowspan=1 colspan=1>This holds the physical segment portion of the return address for anemulator interrupt.</td></tr></table>

<table><tr><td rowspan=1 colspan=1>Name</td><td rowspan=1 colspan=1>Description</td></tr><tr><td rowspan=1 colspan=1>EPSW1</td><td rowspan=1 colspan=1>This holds the PSW from just before a maskable interrupt or a SWlinstruction.</td></tr><tr><td rowspan=1 colspan=1>EPSW2</td><td rowspan=1 colspan=1>This holds the PSW from just before a nonmaskable interrupt.</td></tr><tr><td rowspan=1 colspan=1>EPSW3</td><td rowspan=1 colspan=1>This holds the PSW from just before an emulator interrupt.</td></tr></table>

LR and LCSR are saved by the BL instruction calling a subroutine and restored by the RT instruction ending the subroutine.

The ELR, ECSR, and EPSW registers used depend on the index value from the ELEVEL field in the program status word (PSW). The hardware saves to them during the interrupt acceptance cycle; the RTI instruction at the end of the interrupt handler restores from them.

Note that the sets provide only one register for each level. If subroutines or interrupt handlers are nested, therefore, it is not possible to return with the RT and RTI instructions normally used. The subroutine or interrupt handler must use PUSH instructions to save register contents to the stack before nesting and

return with POP instructions instead.

Choosing the appropriate method for saving these registers depends on the CPU state, so requires particular attention during the design phase. The following pages show how to tailor the user application program to the U8 execution state.

The following describes the programming considerations for each possible ELEVEL setting and for whether the user application program nests subroutine and interrupts.

## A: ELEVEL is 0

An exception level (ELEVEL) setting of zero indicates that there are no interrupt requests pending.   
How procedures begin and end depends solely on whether subroutines are nested.

A-1: Subroutines are not nested.

Beginning of procedure: No special steps necessary.

End of procedure: Restore PC from LR with an RT instruction.

## A-2: Subroutines are nested.

Beginning of procedure: Use PUSH LR instruction to save return address to the stack.

End of procedure: Use POP LR instruction instead of RT to return from subroutine.

Example for A-2  
<!-- image-->

<!-- ===== PDF 第 41-60 页 ===== -->

## B: ELEVEL is 1

An exception level (ELEVEL) setting of 1 indicates a maskable interrupt. In addition to the considerations under A above, how procedures begin and end also depends on whether interrupts are nested.

B-1: Subroutines are not nested.

B-1-1: Interrupts are not nested.

Beginning of procedure: No special steps necessary.

End of procedure: Restore PC from ELR1 and PSW from EPSW1 with an RTI instruction.

B-1-2: Interrupts are nested.

Beginning of procedure: Use PUSH ELR, EPSW instruction to save return address and current PSW to the stack.

End of procedure: Restore PC and PSW from stack with POP LR, PSW instruction instead of RTI.

Example for B-1-1 and B-1-2
<table><tr><td>Intrrpput_B-1-1:; B-1-1 example</td><td></td></tr></table>

<!-- image-->

## B-2: Subroutines are nested.

B-2-1: Interrupts are not nested.

Beginning of procedure: Use PUSH LR instruction to save return address to the stack.

End of procedure: Use POP LR instruction to restore return address and then RTI to return from subroutine.

B-2-2: Interrupts are nested.

Beginning of procedure: Use PUSH LR, ELR, EPSW instruction to save return addresses and current PSW to the stack.

End of procedure: Restore PC and PSW from stack with POP LR, PSW, LR instruction instead of RTI.

Example for B-2-2  
<!-- image-->

## C: ELEVEL is 2

An exception level (ELEVEL) setting of 2 indicates a nonmaskable interrupt. The backup registers used are ELR2, EPSW2, and ECSR2.

C-1: Subroutines are not nested.

Beginning of procedure: No special steps necessary.

End of procedure: Restore PC from ELR2 and PSW from EPSW2 with an RTI instruction.

C-2: Subroutines are nested.

Beginning of procedure: Use PUSH LR instruction to save return address to the stack.

End of procedure: Use POP LR instruction to restore return address and then RTI to return from interrupt handler.

## Example for C-2

<!-- image-->

Choosing the appropriate method for saving these registers depends on the CPU state, so requires particular attention during the design phase.

## 1.5 Interrupt Blocking

As has already been mentioned above, the hardware masks all pending interrupt requests for the duration of the following situations.

(1) Between the start of the interrupt acceptance cycle and the end of the first instruction in the interrupt handler

The hardware delays acceptance of the new interrupt request until it has completed execution of the first instruction in the interrupt handler for the old.

(2) Between a DSR prefix instruction and the immediately following instruction

The hardware delays acceptance of the new interrupt request until it has completed execution of both instructions in the pair.

For further details on DSR prefix instructions, see Section 1.3.4 “DSR Prefix Instructions.” Although a sequence of DSR prefix instructions properly re-enables interrupt requests, such sequences must not appear in program code as they can lead to unintended behavior.

## 1.6 Stack Modifications

This Section summarizes the effects that PUSH and POP instructions have on the stack. For further details, see Chapter 3 “Instruction Descriptions.”

The stack pointer (SP) always moves by an even number of bytes. If the PUSH instruction operand represents an odd number of bytes, the hardware first introduces a dummy cycle that decrements SP without saving any other registers. This dummy cycle writes an indeterminate byte of data to the stack. Similarly, if the POP instruction operand represents an odd number of bytes, the hardware restores the register and then introduces a dummy cycle that increments SP without restoring any registers.

Note that the operation of instructions specifying LR or ELR as the operand depends on the hardware memory model.

The following Figures illustrate the operation of these two instructions.

PUSH R0 / POP R0  
<!-- image-->

PUSH ER0 / POP ER0  
<!-- image-->

PUSH XR0 / POP XR0  
<!-- image-->

PUSH QR0 / POP QR0  
<!-- image-->

PUSH EPSW / POP PSW  
<!-- image-->

PUSH EA / POP EA  
<!-- image-->

PUSH ELR / POP PC (SMALL model)  
<!-- image-->

PUSH ELR / POP PC (LARGE model)  
<!-- image-->

PUSH LR / POP LR (SMALL model)  
<!-- image-->

PUSH LR / POP LR (LARGE model)  
<!-- image-->

## 2. Addressing Types

## 2.1 Addressing Types

The nX-U8/100 architecture has four addressing types:

• register addressing for accessing internal and coprocessor registers

• memory addressing for accessing data memory and program/code memory inside the ROM window

• immediate addressing for specifying numeric values

• program/code memory addressing for accessing program/code memory

## 2.2 Register Addressing

The following register addressing types access the contents of the specified register.
<table><tr><td>Addressing Notation</td><td>Function</td></tr><tr><td>Rn</td><td>This addressing type accesses the contents of the specified byte-sized general register (Rn).</td></tr><tr><td>ERn</td><td>This addressing type accesses the contents of the specified word-sized general register (ERn). When the instruction table lists ERn in an operand, BP may be substituted for ER12 and FP for ER14.</td></tr><tr><td>XRn</td><td>This addressing type accesses the contents of the specified double word-sized general register (XRn).</td></tr><tr><td>QRn</td><td>This addressing type accesses the contents of the specified quad word-sized general register (QRn).</td></tr><tr><td>CRn</td><td>This addressing type accesses the contents of the specified byte-sized coprocessor register (CRn).</td></tr><tr><td>CERn</td><td>This addressing type accesses the contents of the specified word-sized coprocessor register (CERn).</td></tr><tr><td>CXRn</td><td>This addressing type accesses the contents of the specified double word-sized coprocessor register (CXRn).</td></tr><tr><td>CQRn</td><td>This addressing type accesses the contents of the specified quad word-sized coprocessor register (CQRn).</td></tr><tr><td>PC</td><td>This addressing type accesses the contents of the program counter.</td></tr><tr><td>LR</td><td>This addressing type accesses the contents of the link register.</td></tr><tr><td>EA</td><td>This addressing type accesses the contents of the EA register.</td></tr><tr><td>SP</td><td>This addressing type accesses the contents of the stack pointer.</td></tr><tr><td>PSW</td><td>This addressng type accesses the contents of the program status word.</td></tr><tr><td>ELR</td><td>This addressing type accesses the contents of an exception link register.</td></tr><tr><td>ECSR</td><td>This addressing type accesses the contents of a CSR backup register.</td></tr><tr><td>EPSW</td><td>This addressing type accesses the contents of a PSW backup register.</td></tr><tr><td>Rn.bit_offset</td><td>This addressing type accesses the contents of bit specified by bit_offset in general register Rn.</td></tr></table>

## 2.3 Memory Addressing

This addressing type accesses the contents of an address in the data memory space.

Accessing data in a physical segment other than physical segment #0 requires manipulating the data segment register (DSR) with a DSR prefix instruction.

To prevent unintended operation and provide the strongest checking possible of memory access, the U8 assembly language specifications deliberately forbid the use of the DSR prefix instructions in program source code. Instead, use the corresponding DSR prefix inside the memory access instruction itself.

<table><tr><td>DSR Prefix Instruction</td><td>Function</td><td>Corresponding Prefix</td></tr><tr><td>lll0_0oll_iiii_iiii</td><td>Load DSR with the 8-bit pseg_addr : or FAR immediate value iii_ii.</td><td></td></tr><tr><td>1001_00oo_dddd_1111</td><td>Load DSR with the contents Rd : of the general register Rd.</td><td></td></tr><tr><td>l11l_1110_100l_1111</td><td>Use the current DSR value.</td><td>DSR :</td></tr></table>

The following Table shows examples of these prefixes on the left and their results on the right.

<table><tr><td>Assembly Language Source Code</td><td>Actual Instruction Sequence</td></tr><tr><td>LRO， 1:2345H</td><td>DSR ↑1</td></tr><tr><td></td><td>R0 ←[2345H]</td></tr><tr><td>L RO，R1:[ER2]</td><td>DSR ← R1</td></tr><tr><td></td><td>RO←[ER2]</td></tr><tr><td>ST R1， DSR:[EA]</td><td>[(DSR&lt;&lt;l6）|EA]← R1</td></tr></table>

The underlined portions in the above Table indicate the DSR prefixes producing the desired DSR manipulations.

If there is no DSR prefix, the instruction accesses physical segment #0 in the data memory space.

## 2.3.1 Register Indirect Addressing

The following register indirect addressing types access the contents of the data memory address in the specified register.

<table><tr><td>Addressing Notation</td><td colspan="2">Function</td></tr><tr><td>[EA]</td><td colspan="2">This addressing type accesses the contents of the data memory space at the offset in the EA register. Effective address calculation Effective address</td></tr><tr><td></td><td>15 EA</td><td>15 0 +</td></tr><tr><td>pseg_addr:[EA]</td><td colspan="2">This variant uses the physical segment number specified by #pseg_addr.</td></tr><tr><td>DSR:[EA]</td><td colspan="2">This variant uses the physical segment number in DSR.</td></tr><tr><td>Rd:[EA]</td><td colspan="2">This variant uses the physical segment number in general register Rd. This addressing type accesses the contents of the data memory space at the</td></tr><tr><td>[EA+]</td><td colspan="2">offset in the EA register. After the access, the contents of the EA register are incremented by the</td></tr><tr><td></td><td colspan="2">operand size in bytes and,for all sizes except byte,rounded down to an even address.</td></tr><tr><td></td><td>Operand size EA Contents</td><td>Increment</td></tr><tr><td></td><td>Even Odd</td><td>1 1</td></tr><tr><td></td><td>Even</td><td>2</td></tr><tr><td></td><td>Odd Double word Even</td><td>1 4</td></tr><tr><td></td><td>Odd Quad word</td><td>3 8</td></tr><tr><td></td><td>Even Odd</td><td>7</td></tr><tr><td></td><td>Effective address calculation Effective address 0</td><td>15</td></tr><tr><td></td><td>EA</td><td>+</td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td>Contents incremented</td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td>after access</td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td>pseg_addr:[EA+]</td><td colspan="2">This variant uses the physical segment number specified by #pseg_addr.</td></tr><tr><td>DSR:[EA+]</td><td colspan="2">This variant uses the physical segment number in DSR.</td></tr><tr><td>Rd:[EA+]</td><td colspan="2">This variant uses the physical segment number in general register Rd.</td></tr><tr><td>[ERn]</td><td colspan="2">This addressing type accesses the contents of the data memory space at the</td></tr><tr><td></td><td colspan="2">offset in the word-sized general register ERn. [BP] instead of [ER12] and</td></tr><tr><td></td><td colspan="2">[FP] instead of [ER14] are also acceptable.</td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td><img src="images/3b374995c7edcff804f72f4c76c1b0c5ac11aae07bbf370d3dcf4089c245aaa1.jpg"/></td></tr><tr><td>pseg_addr:[ERn]</td><td></td><td>This variant uses the physical segment number specified by #pseg_addr.</td></tr><tr><td></td><td colspan="2"></td></tr><tr><td>DSR:[ERn]</td><td colspan="2">This variant uses the physical segment number in DSR.</td></tr><tr><td>Rd:[ERn]</td><td colspan="2">This variant uses the physical segment number in general register Rd.</td></tr><tr><td>Disp16[ERn]</td><td colspan="2">This addressing type accesses the contents of the data memory space at the byte address formed by adding the displacement Displ6 to the contents of</td></tr><tr><td></td><td>the word-sized general register ERn.</td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td><img src="images/168d9241e2a4924baa80a3e6a4cb563d7f864e1a22e593e10d66aedd5acf508e.jpg"/></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td>pseg_addr:Displ6[ERn]This variant uses the physical segment number specified by #pseg_addr.</td><td></td></tr><tr><td>DSR:Disp16[ERn]</td><td>This variant uses the physical segment number in DSR.</td><td></td></tr></table>

Chapter 2. Addressing Types Instruction Set
<table><tr><td>Addressing Notation</td><td>Function</td></tr><tr><td></td><td>This addressing type accesses the contents of the data memory space at the byte address formed by adding the sign-extended displacement Disp6 to the contents of the base pointer (BP). If there is no DSR prefix, this addressing type accesses physical segment #0 in the data memory space.</td></tr><tr><td></td><td>Effective address calculation Effective address 15 0 BP(=ER12) 15 15 5 0</td></tr><tr><td>pseg_addr:Disp6[BP]</td><td>Sign extension Disp6 This variant uses the physical segment number specified by #pseg_addr.</td></tr><tr><td>DSR:Disp6[BP]</td><td>This variant uses the physical segment number in DSR.</td></tr><tr><td>Rd:Disp6[BP]</td><td>This variant uses the physical segment number in general register Rd.</td></tr><tr><td>Disp6[FP]</td><td>This addressing type accesses the contents of the data memory space at the</td></tr><tr><td></td><td>byte address formed by adding the sign-extended displacement Disp6 to the</td></tr><tr><td></td><td>contents of the frame pointer (FP).</td></tr><tr><td></td><td></td></tr><tr><td></td><td>If there is no DSR prefix, this addressing type accesses physical segment #0</td></tr><tr><td></td><td> in the data memory space.</td></tr><tr><td></td><td></td></tr><tr><td></td><td>Effective address calculation</td></tr><tr><td></td><td>15 0</td></tr><tr><td></td><td>FP(=ER14)</td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td>15 5 0</td></tr><tr><td></td><td>Sign extension Disp6</td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td>pseg_addr:Disp6[FP]</td><td></td></tr><tr><td>1</td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td> This variant uses the physical segment number specified by #pseg_addr.</td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td>DSR:Disp6[FP]</td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td>This variant uses the physical segment number in DSR.</td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td>Rd:Disp6[FP]</td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td></td></tr><tr><td></td><td>This variant uses the physical segment number in general register Rd.</td></tr></table>

## 2.3.2 Direct Addressing

The following direct addressing types access the contents of the specified data memory address.

<table><tr><td>Addressing Notation</td><td colspan="2">Function</td></tr><tr><td>Dadr</td><td colspan="2">This addressing type accesses the contents of the data memory space at the byte address in the instruction.</td></tr><tr><td></td><td colspan="2">Effective address</td></tr><tr><td></td><td>15 0</td><td></td></tr><tr><td></td><td>Dadr16</td><td></td></tr><tr><td>pseg_addr:Dadr</td><td>This variant uses the physical segment number pseg_addr.</td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td>DSR:Dadr</td><td>This variant uses the physical segment number in DSR.</td><td></td></tr><tr><td>Rd:Dadr</td><td></td><td>This variant uses the physical segment number in general register Rd.</td></tr><tr><td>Dbitadr</td><td>This addressing type accesses the contents of the data memory space at the</td><td></td></tr><tr><td></td><td>bit address (Dadr.bit_offset) in the instruction.</td><td></td></tr><tr><td></td><td></td><td>address</td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td><img src="images/e635d63ebf61ece69b9d340cb245109baabfcade2ea82f7becf9d97a9ba30010.jpg"/></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td>pseg_addr:Dbitadr</td><td>This variant uses the physical segment number pseg_addr.</td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td>DSR:Dbitadr</td><td>This variant uses the physical segment number in DSR.</td><td></td></tr><tr><td></td><td></td><td></td></tr><tr><td>Rd:Dbitadr</td><td>This variant uses the physical segment number in general register Rd.</td><td></td></tr></table>

## 2.4 Immediate Addressing

The following immediate value addressing types use an immediate value contained in the instruction.

<table><tr><td>Addressing Notation</td><td>Function</td></tr><tr><td>#imm8</td><td>The specified value is treated as an 8-bit immediate value.</td></tr><tr><td>#signed8</td><td>The specified value is treated as a signed 8-bit immediate value.</td></tr><tr><td rowspan="3"></td><td>The instruction ADD SP, #imm8 treats imm8 as signed8.</td></tr><tr><td>The valid range for signed8 is between -128 and +127.</td></tr><tr><td>The specified value is treated as an unsigned 8-bit immediate value.</td></tr><tr><td rowspan="3">#unsigned8</td><td>The instruction MOV PSW, #imm8 treats imm8 as unsigned8.</td></tr><tr><td>The valid range for unsigned8 is between O and OFFH.</td></tr><tr><td></td></tr><tr><td rowspan="2">#width</td><td>The specified value is treated as a shift size.</td></tr><tr><td>The valid range for width is between O and 7.</td></tr><tr><td rowspan="2">#snum</td><td>The specified value is treated as a SWI instruction vector number.</td></tr><tr><td>The valid range for snum7 is between O and 63.</td></tr><tr><td>#imm7</td><td>The specified value is treated as a signed 7-bit immediate value.</td></tr></table>

<!-- ===== PDF 第 61-80 页 ===== -->

## 2.5 Program/Code Memory Addressing

The following addressing types access the contents of program/code memory addresses.

<table><tr><td>Addressing Notation</td><td colspan="2">Function</td></tr><tr><td>Cadr</td><td colspan="2">This addressing type specifies the 2O-bit branch target address for the B and BL instructions. Note that it includes a physical segment number,so the instruction can produce a branch to a different physical segment. Effective address</td></tr><tr><td></td><td colspan="2">This addressing type specifies a relative branch target address for the conditional branch instructions and optimized branch directives.The target must be in within the same physical segment.</td></tr><tr><td>ERn</td><td colspan="2">This addressing type specifies the contents of a word-sized general register ERn as the branch target offset for the B and BL instructions. The target must be in within the same physical segment. Effective address</td></tr></table>

## 3. Instruction Descriptions

This Chapter describes the detailed operation of each instruction.

## 3.1 Overview

nX-U8/100 core instructions have between zero and two operands. When there are two, the first is the destination; the second, the source.

These operands use the addressing types described in Chapter 2.

For ease of explication, this document uses the following symbols to describe instruction operation.

<table><tr><td> Symbol</td><td>Meaning</td></tr><tr><td>↑</td><td>Assignment</td></tr><tr><td>+or</td><td>Addition</td></tr><tr><td>一</td><td>Subtraction</td></tr><tr><td>*</td><td>Multiplication</td></tr><tr><td>/</td><td>Division</td></tr><tr><td>&gt;</td><td>Shift right</td></tr><tr><td>&lt;</td><td>Shift left</td></tr><tr><td>=</td><td>Equality</td></tr><tr><td>！=</td><td> Inequality</td></tr><tr><td>&amp;</td><td>Bitwise AND</td></tr><tr><td>一</td><td>Bitwise OR</td></tr><tr><td>&lt;</td><td>Bitwise exclusive OR</td></tr><tr><td>~</td><td>Bitwise inversion</td></tr></table>

## 3.2 Instructions by Functional Group

Please refer to Section 3.4 “Instruction Descriptions” about detailed operation of each instruction. Arithmetic Instructions
<table><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td></td><td>Z</td><td></td><td>S OV MIE HC</td><td></td><td></td><td></td><td>Function</td></tr><tr><td>ADD</td><td>Rn</td><td>Rm</td><td>*</td><td></td><td></td><td>*</td><td>*</td><td></td><td>*</td><td>Addition (8-bit)</td><td>Rn←Rn+obj</td></tr><tr><td></td><td></td><td>#imm8</td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td></td><td>*</td><td></td><td></td></tr><tr><td>MOV</td><td>Rn</td><td>Rm</td><td></td><td></td><td>*</td><td>*</td><td></td><td></td><td></td><td>Data transfer (8-bit)</td><td>Rn←obj</td></tr><tr><td></td><td></td><td>#imm8</td><td></td><td></td><td>*</td><td>*</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td>ADDC</td><td>Rn</td><td>Rm</td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td></td><td>*</td><td>Addition with carry</td><td>Rn←Rn+obj+c</td></tr><tr><td></td><td></td><td>#imm8</td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td></td><td>*</td><td></td><td></td></tr><tr><td>CMP</td><td>Rn</td><td>Rm</td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td></td><td>*</td><td>Comparison (8-bit)</td><td>Rn-obj</td></tr><tr><td></td><td></td><td>#imm8</td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td></td><td>＊</td><td></td><td></td></tr><tr><td>CMPC</td><td>Rn</td><td>Rm</td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td></td><td>*</td><td>Comparison with carry</td><td>Rn-obj-c</td></tr><tr><td></td><td></td><td>#imm8</td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td></td><td>*</td><td></td><td></td></tr><tr><td>AND</td><td>Rn</td><td>Rm</td><td></td><td></td><td>*</td><td>★</td><td></td><td></td><td></td><td>Bitwise AND</td><td>Rn←Rn&amp;obj</td></tr><tr><td></td><td></td><td>#imm8</td><td></td><td></td><td>*</td><td>*</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td>OR</td><td>Rn</td><td>Rm</td><td></td><td></td><td>*</td><td>*</td><td></td><td></td><td></td><td>Bitwise OR</td><td>Rn←Rn |obj</td></tr><tr><td></td><td></td><td>#imm8</td><td></td><td></td><td>*</td><td>*</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td>XOR</td><td>Rn</td><td>Rm</td><td></td><td></td><td>*</td><td>★</td><td></td><td></td><td></td><td>Bitwise exclusive OR</td><td>Rn←Rn^obj</td></tr><tr><td></td><td></td><td>#imm8</td><td></td><td></td><td>*</td><td>*</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td>SUB</td><td>Rn</td><td>Rm</td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td></td><td>*</td><td>Subtraction</td><td>Rn←Rn-Rm</td></tr><tr><td>SUBC</td><td>Rn</td><td>Rm</td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td></td><td>*</td><td>Subtraction with carry</td><td>Rn←Rn-Rm-c</td></tr><tr><td>MOV</td><td>ERn</td><td>ERm</td><td></td><td></td><td>￥</td><td></td><td></td><td></td><td></td><td>Data transfer (16-bit)</td><td>ERn←obj</td></tr><tr><td></td><td></td><td>#imm7</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td>ADD</td><td>ERn</td><td>ERm</td><td>*</td><td></td><td>*</td><td></td><td>*</td><td></td><td>*</td><td>Addition (16-bit)</td><td>ERn ←ERn+obj</td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td>*</td><td></td><td>*</td><td></td><td></td></tr><tr><td>CMP</td><td>ERn</td><td>#imm7 ERm</td><td></td><td>* *</td><td>*</td><td>*</td><td>*</td><td></td><td>*</td><td>Comparison (16-bit)</td><td>ERn-ERm</td></tr></table>

## Shift Instructions

<table><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td>Z</td><td>S OV MIE HC</td><td></td><td colspan="7">Function</td></tr><tr><td>SLL</td><td>Rn</td><td>Rm</td><td>*</td><td></td><td>Byte-sized shift left</td><td></td><td>7</td><td></td><td>Rn</td><td></td><td>0</td><td>0</td></tr><tr><td></td><td></td><td>#width</td><td>*</td><td></td><td>logical</td><td>C</td><td>MSB</td><td></td><td></td><td></td><td>LSB</td><td></td></tr><tr><td>SLLC</td><td>Rn</td><td>Rm</td><td>*</td><td></td><td></td><td>15</td><td></td><td>Rn</td><td></td><td>7</td><td>Rn-1</td><td>0</td></tr><tr><td></td><td></td><td></td><td></td><td></td><td>Shift left logical continued</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>#width</td><td>*</td><td></td><td></td><td>C</td><td></td><td></td><td></td><td>shift_data</td><td></td><td></td></tr><tr><td>SRA</td><td>Rn</td><td>Rm</td><td>*</td><td></td><td>Shift right arithmetic</td><td></td><td></td><td></td><td>Rn</td><td></td><td>0</td><td>C</td></tr><tr><td></td><td></td><td>#width</td><td>*</td><td></td><td></td><td>MSB</td><td></td><td></td><td></td><td></td><td>LSB</td><td></td></tr><tr><td>SRL</td><td></td><td>Rm</td><td></td><td></td><td>Shift right logical</td><td></td><td>7</td><td></td><td>Rn</td><td></td><td>0</td><td>C</td></tr><tr><td></td><td>Rn</td><td></td><td></td><td></td><td></td><td>0</td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>#width</td><td>*</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td>LSB</td><td></td></tr><tr><td>SRLC</td><td></td><td></td><td>*</td><td></td><td></td><td>15</td><td>MSB</td><td></td><td>7</td><td></td><td>Rn</td><td></td></tr><tr><td></td><td>Rn</td><td>Rm</td><td></td><td></td><td>Shift right logical</td><td></td><td></td><td>Rn+1</td><td></td><td></td><td>0</td><td>C</td></tr><tr><td></td><td></td><td>#width</td><td>*</td><td></td><td>continued</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr></table>

Load/Store Instructions
<table><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td></td><td></td><td>CZS OV MIE HC</td><td colspan="2">Function</td></tr><tr><td>L</td><td>Rn</td><td>[EA] pseg_addr:[EA]</td><td></td><td>* *</td><td></td><td>Byte-sized data transfer</td><td>Rn←[EA]</td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>DSR:[EA]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>Rd:[EA]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>[EA+]</td><td></td><td></td><td></td><td>Byte-sized data transfer</td><td>Rn←[EA]</td></tr><tr><td></td><td></td><td>pseg_addr:[EA+]</td><td></td><td></td><td></td><td></td><td>EA←EA+1</td></tr><tr><td></td><td></td><td>DSR:[EA+]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>Rd:[EA+]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>[ERm]</td><td></td><td></td><td></td><td>Byte-sized data transfer</td><td>Rn←[ERm]</td></tr><tr><td></td><td></td><td>pseg_addr:[ERm]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>DSR:[ERm]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>Rd:[ERm]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>Disp16[ERm]</td><td></td><td></td><td></td><td>Byte-sized data transfer</td><td>Rn←Disp16[ERm]</td></tr><tr><td></td><td></td><td>pseg_addr:Displ6[ERm]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>DSR:Disp16[ERm]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>Rd:Disp16[ERm]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>Disp6[BP]</td><td></td><td></td><td></td><td>Byte-sized data transfer</td><td>Rn←Disp6[BP]</td></tr><tr><td></td><td></td><td>pseg_addr:Disp6[BP]</td><td></td><td>*</td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>DSR: Disp6[BP]</td><td></td><td>*</td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>Rd:Disp6[BP]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>Disp6[FP]</td><td></td><td>*</td><td></td><td>Byte-sized data transfer</td><td>Rn←Disp6[FP]</td></tr><tr><td></td><td></td><td>pseg_addr:Disp6[FP]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>DSR: Disp6[FP]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>Rd: Disp6[FP]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>Dadr</td><td></td><td></td><td></td><td>Byte-sized data transfer</td><td>Rn←Dadr</td></tr><tr><td></td><td></td><td>pseg_addr:Dadr</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>DSR:Dadr</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td>ERn</td><td></td><td>Rd:Dadr</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>[EA]</td><td></td><td>*</td><td></td><td>Word-sized data</td><td>ERn←[EA]</td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td>transfer</td><td></td></tr><tr><td></td><td></td><td>pseg_addr:[EA]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>DSR:[EA]</td><td></td><td>*</td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>Rd:[EA]</td><td></td><td></td><td></td><td>Word-sized data</td><td>ERn←[EA]</td></tr><tr><td></td><td></td><td>[EA+]</td><td></td><td>*</td><td></td><td>transfer</td><td>EA←EA+1</td></tr><tr><td></td><td></td><td>pseg_addr:[EA+]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>DSR:[EA+] Rd:[EA+]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td>Word-sized data</td><td>ERn←[ERm]</td></tr><tr><td></td><td></td><td>[ERm]</td><td></td><td></td><td></td><td>transfer</td><td></td></tr><tr><td></td><td></td><td>pseg_addr:[ERm]</td><td></td><td>*</td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>DSR:[ERm]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>Rd:[ERm]</td><td></td><td></td><td></td><td>Word-sized data</td><td>ERn← Disp16[ERm]</td></tr><tr><td></td><td></td><td>Disp16[ERm]</td><td></td><td></td><td></td><td>transfer</td><td></td></tr><tr><td></td><td></td><td>pseg_addr: Displ6[ERm]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>DSR:Disp16[ERm] Rd:Disp16[ERm]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td>Word-sized data</td><td>ERn←Disp6[BP]</td></tr><tr><td></td><td></td><td>Disp6[BP]</td><td></td><td></td><td></td><td>transfer</td><td></td></tr><tr><td></td><td></td><td>pseg_addr:Disp6[BP] DSR: Disp6[BP]</td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>Rd: Disp6[BP]</td><td></td><td></td><td></td><td></td><td>ERn←Disp6[FP]</td></tr><tr><td></td><td></td><td>Disp6[FP]</td><td></td><td></td></tr><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td>CN</td><td></td><td>SOV MIE HC</td><td colspan="2">Function</td></tr><tr><td rowspan="10">L</td><td rowspan="10">XRn</td><td>[EA]</td><td></td><td>*</td><td>*</td><td rowspan="3">Double word-sized data</td><td rowspan="3">XRn←[EA]</td></tr><tr><td>pseg_addr:[EA]</td><td>*</td><td></td><td>*</td></tr><tr><td>DSR:[EA]</td><td></td><td></td><td></td></tr><tr><td>Rd:[EA]</td><td></td><td></td><td>*</td><td colspan="2"></td></tr><tr><td>[EA+]</td><td></td><td></td><td>*</td><td rowspan="4">Double word-sized data transfer</td><td rowspan="4">XRn← [EA] EA←EA+1</td></tr><tr><td>pseg_addr:[EA+]</td><td></td><td></td><td></td></tr><tr><td>DSR:[EA+]</td><td></td><td></td><td></td></tr><tr><td>Rd:[EA+]</td><td></td><td></td><td></td></tr><tr><td rowspan="6">QRn</td><td>[EA]</td><td></td><td></td><td></td><td rowspan="4">Quad word-sized data transfer</td></tr><tr><td>pseg_addr:[EA]</td><td></td><td></td><td></td></tr><tr><td>DSR:[EA]</td><td></td><td></td><td></td></tr><tr><td>Rd:[EA]</td><td></td><td>* *</td><td>Quad word-sized data</td></tr><tr><td>[EA+]</td><td></td><td></td><td></td><td colspan="3" rowspan="4"></td></tr><tr><td>pseg_addr:[EA+]</td><td></td><td>*</td><td>*</td><td colspan="2"></td></tr><tr><td></td><td>DSR:[EA+]</td><td></td><td>*</td><td colspan="3"></td></tr><tr><td></td><td>Rd:[EA+]</td><td></td><td></td><td colspan="3"></td></tr></table>

<table><tr><td>Mnemonic ST</td><td>First operand</td><td>Second operand</td><td>CZS OV MIE HC</td><td colspan="2">Function</td></tr><tr><td rowspan="5"></td><td>Rn</td><td>[EA] pseg_addr:[EA] DSR:[EA] Rd:[EA] [EA+]</td><td></td><td>Byte-sized data transfer</td><td>[EA]←Rn</td></tr><tr><td></td><td>pseg_addr:[EA+] DSR:[EA+] Rd:[EA+]</td><td></td><td>Byte-sized data transfer</td><td>[EA]←Rn EA←EA+1</td></tr><tr><td>[ERm]</td><td>pseg_addr:[ERm] DSR:[ERm]</td><td></td><td>Byte-sized data transfer</td><td>[ERm]←Rn</td></tr><tr><td>Rd:[ERm] Disp16[ERm]</td><td>pseg_addr: Displ6[ERm] DSR:Displ6[ERm] Rd:Displ6[ERm]</td><td></td><td>Byte-sized data transfer</td><td>Displ6[ERm] ←Rn</td></tr><tr><td>Disp6[BP] DSR: Disp6[BP]</td><td>pseg_addr:Disp6[BP]</td><td></td><td>Byte-sized data transfer</td><td>Disp6[BP]←Rn</td></tr><tr><td rowspan="3">ERn</td><td></td><td>Rd: Disp6[BP] Disp6[FP] pseg_addr:Disp6[FP] DSR: Disp6[FP]</td><td></td><td>Byte-sized data transfer</td><td>Disp6[FP]←Rn</td></tr><tr><td>Dadr</td><td>Rd:Disp6[FP] pseg_addr:Dadr DSR:Dadr</td><td></td><td>Byte-sized data transfer</td><td>[Dadr]←Rn</td></tr><tr><td>Rd:Dadr [EA] DSR:[EA] Rd:[EA]</td><td></td><td></td><td>Word-sized data transfer</td><td>[EA]←ERn</td></tr><tr><td rowspan="3"></td><td></td><td>pseg_addr:[EA] [EA+]</td><td></td><td>Word-sized data transfer</td><td>[EA]←ERn</td></tr><tr><td>pseg_addr:[EA+] DSR:[EA+] Rd:[EA+]</td><td></td><td></td><td></td><td>EA←EA+1</td></tr><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td>CZ S OV MIE HC</td><td></td><td>Function</td></tr><tr><td rowspan="8">ST</td><td rowspan="8">ERn</td><td>[ERm] pseg_addr:[ERm] DSR:[ERm] Rd:[ERm]</td><td></td><td>Word-sized data transfer</td><td>[ERm]←ERn</td></tr><tr><td>Displ6[ERm] pseg_addr: Displ6[ERm] DSR:Disp16[ERm]</td><td></td><td>Word-sizeddata transfer</td><td>Displ6[ERm] ←ERn</td></tr><tr><td>Disp6[BP] pseg_addr:Disp6[BP] DSR: Disp6[BP] Rd: Disp6[BP]</td><td></td><td>Word-sized data transfer</td><td>Disp6[BP]←ERn</td></tr><tr><td>Disp6[FP] pseg_addr:Disp6[FP] DSR: Disp6[FP] Rd: Disp6[FP]</td><td></td><td>Word-sizeddata transfer</td><td>Disp6[FP]←ERn</td></tr><tr><td>Dadr pseg_addr: Dadr DSR:Dadr Rd:Dadr</td><td></td><td>Word-sized data transfer</td><td>[Dadr]←ERn</td></tr><tr><td>[EA] pseg_addr:[EA] DSR:[EA] Rd:[EA]</td><td></td><td>transfer</td><td>Double word-sized data [EA]←XRn</td></tr><tr><td>[EA+] pseg_addr:[EA+] DSR:[EA+] Rd:[EA+]</td><td></td><td>Double word-sized data transfer</td><td>[EA]←XRn EA←EA+1</td></tr><tr><td>[EA] pseg_addr:[EA] DSR:[EA]</td><td></td><td>Quad word-sized data transfer</td><td>[EA]←QRn</td></tr><tr><td rowspan="2"></td><td>Rd:[EA] [EA+]</td><td></td><td></td><td>Quad word-sized data</td><td>[EA]←QRn</td></tr><tr><td>pseg_addr:[EA+] DSR:[EA+] Rd:[EA+]</td><td></td><td></td><td>transfer</td><td>EA←EA+1</td></tr></table>

Control Register Access Instructions
<table><tr><td>Mnemonic</td><td>First operand</td><td>Second C Z S OV MIE HC operand</td><td></td><td>Function</td></tr><tr><td>ADD</td><td>SP</td><td>#signed8</td><td>Addition</td><td>SP←SP+signed8 if ELEVEL is zero</td></tr><tr><td rowspan="7">MOV</td><td>ECSR</td><td>Rm</td><td>Data transfer</td><td>LCSR←Rm if ELEVELis nonzero ECSR[ELEVEL]←Rm</td></tr><tr><td>ELR</td><td>ERm</td><td>Data transfer</td><td>if ELEVEL is zero LR←ERm if ELEVELis nonzero</td></tr><tr><td>EPSW</td><td>Rm</td><td>Data transfer</td><td>ELR[ELEVEL]←ERm if ELEVELis nonzero EPSW[ELEVEL]←Rm</td></tr><tr><td>ERn</td><td>ELR</td><td>Data transfer</td><td>if ELEVEL is zero ERn←LR if ELEVEL is nonzero</td></tr><tr><td rowspan="2">PSW</td><td>SP</td><td></td><td>ERn←ELR[ELEVEL]</td></tr><tr><td>* * * * *</td><td>Data transfer</td><td>ERn←-SP</td></tr><tr><td></td><td>Rm #unsigned8 * * * * *</td><td>* Data transfer * Data transfer</td><td>PSW←Rm PSW←unsigned8</td></tr><tr><td rowspan="4">Rn</td><td rowspan="2">ECSR</td><td rowspan="2"></td><td rowspan="2"></td><td></td></tr><tr><td>if ELEVEL is zero</td></tr><tr><td rowspan="2">EPSW</td><td rowspan="2"></td><td rowspan="2">Data transfer</td><td>Rn←LCSR if ELEVELis nonzero</td></tr><tr><td>Rn←ECSR[ELEVEL]</td></tr><tr><td rowspan="2">PSW SP ERm</td><td rowspan="2"></td><td rowspan="2">Data transfer</td><td rowspan="2">Data transfer Data transfer</td><td>if ELEVELis nonzero Rn←EPSW[ELEVEL]</td></tr><tr><td>Rn←-PSW</td></tr></table>

PUSH/POP Instructions
<table><tr><td>Mnemonic</td><td>First operand</td><td>Second CZ S OV MIE HC operand</td><td></td><td>Function</td></tr><tr><td rowspan="5">PUSH</td><td>ERn</td><td></td><td>General register save</td><td>SP←SP-n Stack ← General register</td></tr><tr><td>Rn</td><td></td><td></td><td></td></tr><tr><td>QRn XRn</td><td></td><td></td><td></td></tr><tr><td>register_list</td><td></td><td>Control register save</td><td>SP←SP-n</td></tr><tr><td></td><td></td><td>General register</td><td>Stack ← Register set General register← Stack</td></tr><tr><td rowspan="5">POP</td><td>ERn</td><td></td><td>restore</td><td>SP←SP+n</td></tr><tr><td>Rn</td><td></td><td></td><td></td></tr><tr><td>QRn</td><td></td><td></td><td></td></tr><tr><td>XRn</td><td></td><td>Control register</td><td>Register set ← Stack*1</td></tr><tr><td>register_list</td><td></td><td>restore</td><td>SP←SP+n</td></tr></table>

\*1: The program status word (PSW) only changes when it is included in register_list.

Coprocessor Data Transfer Instructions
<table><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td>CZS OV MIE HC</td><td></td><td colspan="2">Function</td></tr><tr><td rowspan="5">MOV</td><td>CRn</td><td>Rm</td><td></td><td></td><td>Byte-sized data transfer</td><td>CRn←Rm</td></tr><tr><td rowspan="4">CRn</td><td>[EA] pseg_addr:[EA] DSR:[EA]</td><td></td><td></td><td>Byte-sized data transfer</td><td>CRn←[EA]</td></tr><tr><td>Rd:[EA] [EA+] pseg_addr:[EA+]</td><td></td><td></td><td>Byte-sized data transfer</td><td>CRn←[EA+] EA←EA+1</td></tr><tr><td>DSR:[EA+] Rd:[EA+] [EA]</td><td></td><td></td><td>Word-sized data transfer</td><td>CERn←[EA]</td></tr><tr><td>pseg_addr:[EA] DSR:[EA] Rd:[EA] [EA+]</td><td></td><td></td><td>Word-sized data transfer</td><td>CERn←[EA+]</td></tr><tr><td rowspan="3">CXRn</td><td rowspan="3"></td><td>pseg_addr:[EA+] DSR:[EA+] Rd:[EA+]</td><td></td><td></td><td></td><td>EA←EA+1</td></tr><tr><td>[EA] pseg_addr:[EA] DSR:[EA] Rd:[EA]</td><td></td><td></td><td>Double word-sized data transfer</td><td>CXRn←[EA]</td></tr><tr><td>[EA+] pseg_addr:[EA+] DSR:[EA+]</td><td></td><td></td><td>Double word-sized data transfer</td><td>CXRn ← [EA+] EA←EA+1</td></tr><tr><td rowspan="3"></td><td rowspan="3">CQRn</td><td>Rd:[EA+] [EA]</td><td></td><td></td><td>Quad word-sized</td><td>CQRn ← [EA]</td></tr><tr><td>pseg_addr:[EA] DSR:[EA] Rd:[EA]</td><td></td><td></td><td>continuous data transfer</td><td></td></tr><tr><td>[EA+] pseg_addr:[EA+] DSR:[EA+]</td><td></td><td></td><td>Quad word-sized continuous data transfer</td><td>CQRn ← [EA+] EA←EA+1</td></tr></table>

(continued on next page)

Coprocessor Data Transfer Instructions (continued from previous page)
<table><tr><td>Mnemonic MOV</td><td>First operand</td><td>Second operand</td><td>S OV MIE HC</td><td></td><td>Function</td></tr><tr><td rowspan="7"></td><td>Rn</td><td>CRm</td><td></td><td>Byte-sized data transfer Byte-sized data transfer</td><td>Rn←CRm [EA]←CRm</td></tr><tr><td>[EA] pseg_addr:[EA] DSR:[EA] Rd:[EA]</td><td>CRm</td><td></td><td></td><td></td></tr><tr><td>[EA+] pseg_addr:[EA+] DSR:[EA+] Rd:[EA+] [EA]</td><td>CRm</td><td></td><td>Byte-sized data transfer</td><td>[EA]←CRm EA←EA+1</td></tr><tr><td>pseg_addr:[EA] DSR:[EA] Rd:[EA] [EA+]</td><td>CERm</td><td></td><td>Word-sized data transfer Word-sized data transfer</td><td>[EA]←CERm</td></tr><tr><td>pseg_addr:[EA+] DSR:[EA+] Rd:[EA+] [EA]</td><td>CERm</td><td></td><td>Double word-sized data</td><td>[EA]←CERm EA←EA+1</td></tr><tr><td>pseg_addr:[EA] DSR:[EA] Rd:[EA] [EA+]</td><td>CXRm</td><td></td><td>transfer</td><td>[EA]←CXRm</td></tr><tr><td>pseg_addr:[EA+] DSR:[EA+] Rd:[EA+]</td><td>CXRm</td><td></td><td>Double word-sized data transfer</td><td>[EA]←CXRm EA←EA+1</td></tr><tr><td>[EA] pseg_addr:[EA] DSR:[EA] Rd:[EA]</td><td>CQRm</td><td></td><td></td><td>Quad word-sized continuous data transfer</td><td>[EA]←CQRm</td></tr><tr><td>[EA+] DSR:[EA+] Rd:[EA+]</td><td>pseg_addr:[EA+]</td><td>CQRm</td><td></td><td>Quad word-sized continuous data transfer</td><td>[EA]←CQRm EA←EA+1</td></tr></table>

EA Register Data Transfer Instructions
<table><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td>C</td><td>Z S</td><td>OV MIE HC</td><td></td><td>Function</td></tr><tr><td>LEA</td><td>[ERn]</td><td></td><td></td><td></td><td></td><td>Data transfer to EA</td><td>EA←ERn</td></tr><tr><td></td><td>Disp16[ERm]</td><td></td><td></td><td></td><td></td><td></td><td>EA←Disp16+ERm</td></tr><tr><td></td><td>Dadr</td><td></td><td></td><td></td><td></td><td></td><td>EA← Dadr</td></tr></table>

## ALU Instructions

<table><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td>C Z</td><td>S</td><td>OV MIE HC</td><td></td><td>Function</td></tr><tr><td>DAA</td><td>Rn</td><td></td><td>* *</td><td>*</td><td></td><td></td><td>Byte-sized decimal adjustment for addition</td></tr><tr><td>DAS</td><td>Rn</td><td></td><td>* *</td><td>*</td><td></td><td>*</td><td>Byte-sized decimal adjustment for subtraction</td></tr><tr><td>NEG</td><td>Rn</td><td></td><td>* *</td><td>*</td><td>*</td><td>*</td><td>Negate</td></tr></table>

Bit Access Instructions
<table><tr><td>Mnemonic</td><td>First operand</td><td>Second C Z operand</td><td>S OV MIE HC</td><td>Function</td></tr><tr><td>SB</td><td>Rn.bit_offset</td><td>*</td><td></td><td>Z←~Rn.bit_offset Rn.bit_offset←-1</td></tr><tr><td></td><td>Dbitadr</td><td>*</td><td></td><td></td></tr><tr><td></td><td>pseg_addr: Dbitadr</td><td>*</td><td></td><td>z←~[Dbitadr]</td></tr><tr><td></td><td>DSR: Dbitadr</td><td>*</td><td></td><td>[Dbitadr]←1</td></tr><tr><td></td><td>Rd: Dbitadr</td><td>*</td><td></td><td></td></tr><tr><td>RB</td><td>Rn.bit_offset</td><td>*</td><td></td><td>Z←~Rn.bit_offset</td></tr><tr><td></td><td>Dbitadr</td><td></td><td>Reset bit</td><td>Rn.bit_offset←0</td></tr><tr><td></td><td>pseg_addr: Dbitadr</td><td>* *</td><td></td><td>z←~[Dbitadr]</td></tr><tr><td></td><td>DSR:Dbitadr</td><td>*</td><td></td><td>[Dbitadr]←0</td></tr><tr><td></td><td>Rd: Dbitadr</td><td>*</td><td></td><td></td></tr><tr><td>TB</td><td>Rn.bit_offset</td><td>*</td><td>Test bit</td><td>Z←~Rn.bit_offset</td></tr><tr><td></td><td>Dbitadr</td><td>*</td><td></td><td></td></tr><tr><td></td><td>pseg_addr:Dbitadr</td><td>*</td><td></td><td></td></tr><tr><td></td><td>DSR:Dbitadr</td><td>*</td><td>Test bit</td><td>z←~[Dbitadr]</td></tr><tr><td></td><td>Rd: Dbitadr</td><td>*</td><td></td><td></td></tr></table>

PSW Access Instructions
<table><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td>C</td><td>S 》</td><td>OV MIE HC</td><td></td></tr><tr><td>EI</td><td></td><td></td><td></td><td></td><td>Enable interrupts</td><td>MIE←1</td></tr><tr><td>DI</td><td></td><td></td><td></td><td></td><td>Disable interrupts</td><td>MIE←0</td></tr><tr><td>SC</td><td></td><td></td><td>*</td><td></td><td>Set carry flag</td><td>C←1</td></tr><tr><td>RC</td><td></td><td></td><td>*</td><td></td><td>Reset carry flag</td><td>C←0</td></tr><tr><td>CPLC</td><td></td><td></td><td>*</td><td></td><td>Complement carry flag</td><td>C←-C</td></tr></table>

## Conditional Relative Branch Instructions

<table><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td>C Z S OV MIE HC</td><td>Function</td></tr><tr><td>Bcond</td><td>Radr</td><td></td><td>Conditional branch</td><td>if cond ? Radr : PC+2</td></tr><tr><td>BC</td><td>cond</td><td></td><td></td><td></td></tr></table>

Sign Extension Instruction
<table><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td>C</td><td>S OV MIE HC</td><td></td><td>Function</td></tr><tr><td>EXTBW</td><td>ERn</td><td></td><td></td><td></td><td></td><td>Extend sign ERn←-(sign-extends)Rn</td></tr></table>

Software Interrupt Instructions
<table><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td>C Z</td><td>S OV MIE HC</td><td></td><td></td><td>Function</td></tr><tr><td>swI</td><td>#snum</td><td></td><td></td><td></td><td>*</td><td>Software interrupt instruction</td><td>address← (snum&lt;&lt;1), PC←Vector-table(address)</td></tr><tr><td>BRK</td><td></td><td></td><td></td><td></td><td></td><td>Break instruction</td><td>If ELEVEL greater than 1 System reset If ELEVEL less than 2</td></tr></table>

## Branch Instructions

<table><tr><td>Mnemonic</td><td>First operand</td><td>Second C operand</td><td>Z S OV MIE HC</td><td></td><td>Function</td></tr><tr><td rowspan="2">B</td><td>Cadr</td><td></td><td></td><td>Branch instruction</td><td>CSR ← Cadr[19:16] PC ←Cadr[15:0]</td></tr><tr><td>ERn</td><td></td><td></td><td>Branch</td><td>PC←ERn LR←Address of next instruction</td></tr><tr><td rowspan="2">BL</td><td>Cadr</td><td></td><td></td><td>instruction</td><td>LCSR ←CSR CSR ← Cad[19:16]</td></tr><tr><td>ERn</td><td></td><td></td><td></td><td>PC←Cad[15:0] LR←Address of next instruction LCSR ←CSR PC←ERn</td></tr></table>

## Multiplication and Division Instructions

<table><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td>C</td><td></td><td>S OV MIE HC</td><td></td><td>Function</td></tr><tr><td>MUL</td><td>ERn</td><td>Rm</td><td></td><td>*</td><td></td><td>Multiplication</td><td>ERn←Rn* Rm</td></tr><tr><td>DIV</td><td>ERn</td><td>Rm</td><td></td><td></td><td></td><td>Division</td><td>ERn← ERn/ Rm,Rm← ERn mod Rm</td></tr></table>

## Miscellaneous

<table><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td>C</td><td>Z</td><td>S</td><td>OV MIE HC</td><td></td><td>Function</td><td></td></tr><tr><td>INC</td><td>[EA]</td><td></td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td>Memory increment</td><td>[EA]←[EA] + 1</td></tr><tr><td></td><td>pseg_addr:[EA]</td><td></td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td></td><td></td></tr><tr><td></td><td>DSR:[EA]</td><td></td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td></td><td></td></tr><tr><td></td><td>Rd:[EA]</td><td></td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td></td><td></td></tr><tr><td>DEC</td><td>[EA]</td><td></td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td>Memory decrement</td><td>[EA]←[EA]- 1</td></tr><tr><td></td><td>pseg_addr:[EA]</td><td></td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td></td><td></td></tr><tr><td></td><td>DSR:[EA]</td><td></td><td></td><td>*</td><td>*</td><td>*</td><td>*</td><td></td><td></td></tr><tr><td></td><td>Rd:[EA]</td><td></td><td>*</td><td></td><td>*</td><td>*</td><td>*</td><td></td><td></td></tr><tr><td>RT</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td>Return from subroutine</td><td>CSR ←LCSR</td></tr><tr><td>RTI</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td>PC ←LR</td></tr><tr><td></td><td></td><td></td><td>*</td><td>*</td><td>*</td><td>*</td><td>*</td><td>Return from interrupt</td><td>CSR← ECSR[ELEVEL]</td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td>PC←ELR [ELEVEL]</td></tr><tr><td>NOP</td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td>PSW← EPSW[ELEVEL]</td></tr></table>

## 3.3 Instruction Execution Times

This Section discusses nX-U8/100 core instruction execution times. To eliminate dependencies on clock frequency, it gives these times in clock cycles.

This Section also assumes that memory read and write cycles are all exactly one clock cycle long. In actual practice, however, execution times for instruction accessing slower memory will have to include memory wait cycles.

Each instruction takes at least three machine cycles to execute—one each for instruction fetch, instruction decode, and instruction execution plus result write. The nX-U8/100 architecture, however, pipelines instructions so that these three stages run in parallel, producing, under optimal conditions, faster execution than suggested by the machine cycles counts for the individual instructions. These execution times under optimal conditions are called minimum execution times.

Competition for CPU resources, however, mean that certain instruction sequences cannot run in parallel. The nX-U8/100 architecture resolves such conflicts by inserting a wait cycle at least one machine cycle long into the pipeline, delaying the execution of the later instruction.

There are following three conditions in which a wait cycle is inserted.

(1) Accessing ROM window addresses introduces a wait cycle of n × m machine cycles, where n is the number of bytes accessed and m the memory wait cycles for accessing a single byte. The handling of the Rom window region and the numbers of wait cycles inserted when the Rom window region is accessed differ for every product. Please refer to the manual of each product about the detailed number of cycles at the time of accessing the Rom window region.

(2) When the data region of the physical segment 0 is accessed using [EA+] addressing, the bus inside CPU competes and it becomes the factor which a wait cycle generates.

(3) The NMI interrupt and MI interrupt are influenced of [EA+] addressing. These interrupts require 3 cycles for hardware processing time,however, when the interruption occurs immediately after the physical segment 0 is accessed using [EA+] addressing, the interruption sequence is started after one machine cycle of wait cycles is performed .

The total execution time for an instruction, therefore, is the minimum execution time plus any wait cycles for resolving bus conflicts and any memory wait cycles.

The Table beginning on the next page lists these three quantities for all nX-U8/100 instructions. A blank indicates that the corresponding instruction either does not compete for CPU resources or does not access memory.

<table><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td>Minimum execution time (cycles)</td><td>ROM window access</td><td>[EA+] addressing delay</td></tr><tr><td>ADD</td><td>ERn</td><td>ERm</td><td>2</td><td></td><td></td></tr><tr><td></td><td></td><td>#imm7</td><td>2</td><td></td><td></td></tr><tr><td>ADD</td><td>Rn</td><td>Rm</td><td>1</td><td></td><td></td></tr><tr><td></td><td></td><td>#imm8</td><td>1</td><td></td><td></td></tr><tr><td></td><td>SP</td><td>#signed8</td><td>2</td><td></td><td></td></tr><tr><td>ADDC</td><td>Rn</td><td>Rm</td><td>1</td><td></td><td></td></tr><tr><td></td><td></td><td>#imm8</td><td>1</td><td></td><td></td></tr><tr><td>AND</td><td>Rn</td><td>Rm</td><td>1</td><td></td><td></td></tr><tr><td></td><td></td><td>#imm8</td><td>1</td><td></td><td></td></tr><tr><td>B</td><td>Cadr</td><td></td><td>2</td><td></td><td>1</td></tr><tr><td></td><td>ERn</td><td></td><td>2</td><td></td><td>1</td></tr><tr><td>Bcond</td><td>Radr</td><td></td><td> $1 / 3 _ { ( ^ { * } 1 ) }$ </td><td></td><td>1</td></tr><tr><td>BL</td><td>Cadr</td><td></td><td>2</td><td></td><td>1</td></tr><tr><td></td><td>ERn</td><td></td><td>2</td><td></td><td>1</td></tr><tr><td>BRK</td><td></td><td></td><td>7</td><td></td><td>1</td></tr><tr><td>CMP</td><td>ERn</td><td>ERm</td><td>2</td><td></td><td></td></tr><tr><td></td><td>Rn</td><td>Rm</td><td>1</td><td></td><td></td></tr><tr><td></td><td></td><td>#imm8</td><td>1</td><td></td><td></td></tr><tr><td>CMPC</td><td>Rn</td><td>Rm</td><td>1</td><td></td><td></td></tr><tr><td></td><td></td><td>#imm8</td><td>1</td><td></td><td></td></tr><tr><td>CPLC</td><td></td><td></td><td>1</td><td></td><td></td></tr><tr><td>DAA</td><td>Rn</td><td></td><td>1</td><td></td><td></td></tr><tr><td>DAS</td><td>Rn</td><td></td><td>1</td><td></td><td></td></tr><tr><td>DEC</td><td>[EA] pseg_addr:[EA]</td><td></td><td>2</td><td></td><td></td></tr><tr><td></td><td>DSR:[EA] Rd:[EA]</td><td></td><td>3</td><td></td><td></td></tr><tr><td>DI</td><td></td><td></td><td>3</td><td></td><td></td></tr><tr><td>DIV</td><td>ERn</td><td>Rm</td><td>16</td><td></td><td></td></tr><tr><td>EI</td><td></td><td></td><td>1</td><td></td><td></td></tr><tr><td>EXTBW</td><td>ERn</td><td></td><td>1</td><td></td><td></td></tr><tr><td>INC</td><td>[EA]</td><td></td><td>2</td><td></td><td>1</td></tr><tr><td></td><td>pseg_addr:[EA] DSR:[EA]</td><td></td><td>3</td><td></td><td></td></tr></table>

\*1: The higher count is for when the branching condition is met; the lower one, for when the branching condition is not met.

<table><tr><td>Mnemonic</td><td>First operand</td><td>Second operand</td><td>Minimum execution time (cycles)</td><td>ROM window access</td><td>[EA+] addressing delay</td></tr><tr><td>L</td><td>ERn</td><td>[EA]</td><td>2</td><td>2</td><td></td></tr><tr><td></td><td></td><td>pseg_addr:[EA] DSR:[EA]</td><td>3</td><td>2</td><td></td></tr><tr><td></td><td></td><td>Rd:[EA] [EA+]</td><td>2</td><td>2</td><td></td></tr><tr><td></td><td></td><td>pseg_addr:[EA+] DSR:[EA+] Rd:[EA+]</td><td>3</td><td>2</td><td></td></tr><tr><td></td><td></td><td>[ERm] pseg_addr:[ERm]</td><td>2</td><td>2</td><td></td></tr><tr><td></td><td></td><td>DSR:[ERm]</td><td>3</td><td>2</td><td></td></tr><tr><td></td><td></td><td>Rd:[ERm] Disp16[ERm]</td><td>3</td><td>2</td><td></td></tr><tr><td></td><td></td><td>pseg_addr: Disp16[ERm] DSR:Disp16[ERm]</td><td>4</td><td></td><td></td></tr><tr><td></td><td></td><td>Rd: Disp16[ERm] Disp6[BP]</td><td></td><td>2</td><td></td></tr><tr><td></td><td></td><td>pseg_addr: Disp6[BP]</td><td>3</td><td>2</td><td></td></tr><tr><td></td><td></td><td>DSR: Disp6[BP] Rd: Disp6[BP]</td><td>4</td><td>2</td><td></td></tr><tr><td></td><td></td><td>Disp6[FP] pseg_addr: Disp6[FP]</td><td>3</td><td>2</td><td></td></tr><tr><td></td><td></td><td>DSR: Disp6[FP] Rd:Disp6[FP]</td><td>4</td><td>2</td><td></td></tr><tr><td></td><td></td><td>Dadr pseg_addr: Dadr</td><td>2</td><td>2</td><td>1</td></tr><tr><td></td><td>QRn</td><td>DSR: Dadr Rd: Dadr</td><td>3</td><td>2</td><td></td></tr><tr><td></td><td>[EA] pseg_addr:[EA]</td><td>8</td><td>8</td><td></td><td></td></tr><tr><td></td><td></td><td>DSR:[EA]</td><td>9</td><td>8</td><td></td></tr><tr><td></td><td></td><td>Rd:[EA] [EA+]</td><td>8</td><td>8</td><td></td></tr><tr><td></td><td></td><td></td><td></td><td></td><td></td></tr><tr><td></td><td></td><td>pseg_addr:[EA+] DSR:[EA+] Rd:[EA+]</td><td>9</td><td>8</td><td></td></tr><tr><td>L</td><td>Rn</td><td>[EA] pseg_addr:[EA]</td><td>1</td><td>1</td><td></td></tr><tr><td></td><td></td><td>DSR:[EA] Rd:[EA]</td><td>2</td><td>1</td><td></td></tr><tr><td></td><td></td><td>[EA+]</td><td>1</td><td>1</td><td></td></tr><tr><td></td><td></td><td>pseg_addr:[EA+] DSR:[EA+]</td><td>2</td><td>1</td><td></td></tr><tr><td></td><td></td><td>Rd:[EA+] [ERm]</td><td>1</td><td>1</td><td></td></tr><tr><td></td><td></td><td>pseg_addr:[ERm] DSR:[ERm]</td><td>2</td><td>1</td><td></td></tr><tr><td></td><td></td><td>Rd:[ERm] Disp16[ERm] pseg_addr: Displ6[ERm]</td><td>2</td><td>1</td><td></td></tr><tr><td></td><td></td><td>DSR:Disp16[ERm]</td><td>3</td><td></td><td></td></tr><tr><td></td><td></td><td>Rd: Disp16[ERm] Disp6[BP]</td><td>2</td><td>1</td><td></td></tr><tr><td></td><td></td><td>pseg_addr: Disp6[BP] DSR: Disp6[BP]</td><td>3</td><td>1</td><td></td></tr><tr><td></td><td></td><td>Rd: Disp6[BP] Disp6[FP]</td><td>2</td><td></td><td></td></tr><tr><td></td><td></td><td>pseg_addr: Disp6[FP] DSR: Disp6[FP]</td><td>3</td><td></td><td></td></tr><tr><td></td><td></td><td>Rd: Disp6[FP] Dadr</td><td>2</td><td>1</td><td></td></tr><tr><td></td><td></td><td>pseg_addr: Dadr DSR: Dadr</td><td>3</td><td>1</td><td></td></tr><tr><td>XRn</td><td>Rd: Dadr [EA]</td><td></td><td>4</td><td>4</td><td></td></tr><tr><td></td><td>DSR:[EA]</td><td>pseg_addr:[EA]</td><td>5</td><td>4</td><td></td></tr><tr><td></td><td>Rd:[EA] [EA+]</td><td></td><td>4</td><td>4</td><td></td></tr><tr><td></td><td>DSR:[EA+]</td><td>pseg_addr:[EA+]</td><td>5</td><td>4</td><td></td></tr><tr><td rowspan="2">LEA</td><td rowspan="2">[ERm] Disp16[ERm]</td><td></td><td>1</td><td></td><td></td></tr><tr><td></td><td>2</td><td></td><td></td></tr><tr><td rowspan="8">MOV</td><td rowspan="4">Dadr CERn</td><td>[EA]</td><td>2 2</td><td>2</td><td></td></tr><tr><td>pseg_addr:[EA] DSR:[EA] Rd:[EA]</td><td>3</td><td>2</td><td></td></tr><tr><td>[EA+] pseg_addr:[EA+]</td><td>2</td><td>2</td><td></td></tr><tr><td>DSR:[EA+] Rd:[EA+]</td><td>3</td><td>2</td><td></td></tr><tr><td rowspan="5">CQRn</td><td>[EA]</td><td>8</td><td>8</td><td></td></tr><tr><td>pseg_addr:[EA] DSR:[EA]</td><td>9</td><td></td><td></td></tr><tr><td>Rd:[EA] [EA+]</td><td>8</td><td>8</td><td></td></tr><tr><td>pseg_addr:[EA+] DSR:[EA+]</td><td>9</td><td>8</td><td></td></tr><tr><td>Rd:[EA+] [EA]</td><td>1</td><td>1</td><td colspan="2"></td></tr><tr><td rowspan="4"></td><td>pseg_addr:[EA] DSR:[EA]</td><td>2</td><td></td><td colspan="2"></td></tr><tr><td>Rd:[EA] [EA+]</td><td>1</td><td>1</td><td colspan="2"></td></tr><tr><td>pseg_addr:[EA+] DSR:[EA+]</td><td>2</td><td>1</td><td colspan="2"></td></tr><tr><td>Rd:[EA+] Rm</td><td></td><td></td><td colspan="2"></td></tr><tr><td>CXRn</td><td>[EA] pseg_addr:[EA]</td><td>1 4</td><td>4</td><td colspan="2"></td></tr><tr><td rowspan="4"></td><td>DSR:[EA] Rd:[EA]</td><td>5</td><td>4</td><td colspan="2"></td></tr><tr><td>[EA+] pseg_addr:[EA+]</td><td>4</td><td>4</td><td colspan="2"></td></tr><tr><td>DSR:[EA+]</td><td>5</td><td>4</td><td colspan="2"></td></tr><tr><td>Rd:[EA+] Rm</td><td></td><td></td><td colspan="2"></td></tr><tr><td>ELR</td><td>ERm</td><td>2 3</td><td></td><td colspan="2"></td></tr><tr><td>EPSW</td><td>Rm</td><td></td><td></td><td colspan="2"></td></tr><tr><td></td><td></td><td>2</td><td></td><td colspan="2"></td></tr><tr><td>ERn</td><td>ELR</td><td>3</td><td></td><td colspan="2"></td></tr><tr><td></td><td>ERm</td><td>2</td><td></td><td colspan="2"></td></tr><tr><td></td><td>#imm7</td><td>2</td><td></td><td colspan="2"></td></tr><tr><td></td><td>SP</td><td>2</td><td></td><td colspan="2"></td></tr><tr><td>MOV</td><td>[EA]</td><td>CERm</td><td>2</td><td>2</td><td>1</td></tr><tr><td rowspan="8"></td><td>pseg_addr:[EA] DSR:[EA]</td><td>CERm</td><td>3</td><td>2</td><td></td></tr><tr><td>Rd:[EA] [EA+]</td><td>CERm</td><td>2</td><td>2</td><td></td></tr><tr><td>pseg_addr:[EA+] DSR:[EA+]</td><td>CERm</td><td>3</td><td>2</td><td></td></tr><tr><td>Rd:[EA+] [EA]</td><td>CQRm</td><td>8</td><td>8</td><td></td></tr><tr><td>pseg_addr:[EA] DSR:[EA]</td><td>CQRm</td><td>9</td><td>8</td><td></td></tr><tr><td>Rd:[EA] [EA+]</td><td>CQRm</td><td>8</td><td>8</td><td></td></tr><tr><td>pseg_addr:[EA+] DSR:[EA+]</td><td>CQRm</td><td>9</td><td>8</td><td></td></tr><tr><td>Rd:[EA+] [EA]</td><td>CRm</td><td>1</td><td>1</td><td></td></tr><tr><td>pseg_addr:[EA] DSR:[EA] Rd:[EA]</td><td>CRm</td><td>2</td><td>1</td><td colspan="2"></td></tr><tr><td>[EA+]</td><td>CRm</td><td>1</td><td>1</td><td colspan="2"></td></tr><tr><td>pseg_addr:[EA+] DSR:[EA+]</td><td>CRm</td><td>2</td><td></td><td colspan="2"></td></tr><tr><td>Rd:[EA+] [EA]</td><td></td><td>4</td><td></td><td colspan="2"></td></tr><tr><td>pseg_addr:[EA] DSR:[EA]</td><td>CXRm</td><td></td><td>4</td><td colspan="2"></td></tr><tr><td>Rd:[EA] [EA+]</td><td>CXRm</td><td>5</td><td>4</td><td colspan="2"></td></tr><tr><td>pseg_addr:[EA+] DSR:[EA+]</td><td>CXRm CXRm</td><td>4 5</td><td>4 4</td><td colspan="2"></td></tr><tr><td>Rd:[EA+] PSW</td><td></td><td></td><td></td><td colspan="2"></td></tr><tr><td></td><td>Rm</td><td>1</td><td></td><td colspan="2"></td></tr><tr><td>Rn</td><td>#unsigned8</td><td>1</td><td></td><td colspan="2"></td></tr><tr><td></td><td>CRm</td><td>1</td><td></td><td colspan="2"></td></tr><tr><td></td><td>ECSR</td><td>2</td><td></td><td colspan="2"></td></tr><tr><td></td><td>EPSW</td><td>2</td><td></td><td colspan="2"></td></tr><tr><td></td><td>PSW</td><td>1</td><td></td><td colspan="2"></td></tr><tr><td></td><td>Rm</td><td>1</td><td></td><td colspan="2"></td></tr><tr><td></td><td>#imm8</td><td>1</td><td></td><td colspan="2"></td></tr><tr><td>SP</td><td>ERm</td><td>1</td><td></td><td colspan="2"></td></tr></table>