/*
Cubesat Space Protocol - A small network-layer protocol designed for Cubesats
Copyright (C) 2012 Gomspace ApS (http://www.gomspace.com)
Copyright (C) 2012 AAUSAT3 Project (http://aausat3.space.aau.dk) 

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include <csp/csp.h>
#include <csp/csp_error.h>

#include <csp/arch/csp_system.h>

int csp_sys_tasklist(char * out) {
	strcpy(out, "Tasklist not available on OSX");
	return CSP_ERR_NONE;
}

uint32_t csp_sys_memfree(void) {
	/* TODO: Fix memory free on OSX */
	uint32_t total = 0;
	return total;
}

int csp_sys_reboot(void) {
	/* TODO: Fix reboot on OSX */
	csp_log_error("Failed to reboot\r\n");

	return CSP_ERR_INVAL;
}

void csp_sys_set_color(csp_color_t color) {

	unsigned int color_code, modifier_code;
	switch (color & COLOR_MASK_COLOR) {
		case COLOR_BLACK:
			color_code = 30; break;
		case COLOR_RED:
			color_code = 31; break;
		case COLOR_GREEN:
			color_code = 32; break;
		case COLOR_YELLOW:
			color_code = 33; break;
		case COLOR_BLUE:
			color_code = 34; break;
		case COLOR_MAGENTA:
			color_code = 35; break;
		case COLOR_CYAN:
			color_code = 36; break;
		case COLOR_WHITE:
			color_code = 37; break;
		case COLOR_RESET:
		default:
			color_code = 0; break;
	}
	
	switch (color & COLOR_MASK_MODIFIER) {
		case COLOR_BOLD:
			modifier_code = 1; break;
		case COLOR_UNDERLINE:
			modifier_code = 2; break;
		case COLOR_BLINK:
			modifier_code = 3; break;
		case COLOR_HIDE:
			modifier_code = 4; break;
		case COLOR_NORMAL:
		default:
			modifier_code = 0; break;
	}

	printf("\033[%u;%um", modifier_code, color_code);
}
