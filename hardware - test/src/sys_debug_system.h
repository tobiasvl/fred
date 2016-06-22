// *******************************************************************************************************************************
// *******************************************************************************************************************************
//
//		Name:		debug_system.h
//		Purpose:	Debugger Code (System Dependent) Header
//		Created:	21st June 2016
//		Author:		Paul Robson (paul@robsons.org.uk)
//
// *******************************************************************************************************************************
// *******************************************************************************************************************************

#include "sys_processor.h"
#include "hardware.h"

#ifndef _DEBUG_SYS_H
#define _DEBUG_SYS_H
#include "sys_processor.h"

#define WIN_TITLE 		"RCA Fred Emulator"											// Initial Window stuff
#define WIN_WIDTH		(32*8*4)
#define WIN_HEIGHT		(23*8*4+64)
#define WIN_BACKCOLOUR	0x004

// *******************************************************************************************************************************
//							These functions need to be implemented by the dependent debugger.
// *******************************************************************************************************************************

#define DEBUG_ARGUMENTS(ac,av) if (ac == 2) CPULoadBinary(argv[1]);					// Handle CLI arguments

#define DEBUG_CPURENDER(x) 	DBGXRender(x)											// Render the debugging display
#define DEBUG_VDURENDER(x)	DBGXRender(x)											// Render the game display etc.

#define DEBUG_RESET() 		CPUReset()												// Reset the CPU / Hardware.
#define DEBUG_HOMEPC()		((CPUGetStatus()->pc) & 0xFFFF) 						// Get PC Home Address (e.g. current PCTR value)

#define DEBUG_SINGLESTEP()	CPUExecuteInstruction()									// Execute a single instruction, return 0 or Frame rate on frame end.
#define DEBUG_RUN(b1,b2) 	CPUExecute(b1,b2) 										// Run a frame or to breakpoint, returns -1 if breakpoint
#define DEBUG_GETOVERBREAK() CPUGetStepOverBreakpoint()								// Where would we break to step over here. (0 == single step)

#define DEBUG_RAMSTART 		(0x0000)												// Initial RAM address for debugger.
#define DEBUG_SHIFT(d,v)	((((d) << 4) | v) & 0xFFFF)								// Shifting into displayed address.

#define DEBUG_KEYMAP(k,r)	HWIProcessKey(k,r)

void DBGXRender(int *address);														// Render the debugger screen.
void DBGXRenderDisplay(void);
void DBGXLoad(char *file);

#endif