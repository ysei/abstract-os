/*
 * AbastractOS
 * Copyright (C) 2011 Davide Gessa
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */
#ifndef VESA_HPP
#define VESA_HPP

extern "C"
{
	#include "Kernel/arch/x86/multiboot.h"
	#include <klibc/malloc.h>
	#include <types.h>
	#include <klibc/string.h>
	#include <config.h>
}	
#include <Driver.hpp>




/**
 * Vesa video driver
 */
class VesaDriver : public Driver
{
	public:
	
		typedef struct
		{
		    char signature[4];
		    uint16_t version;
		    uint32_t oem_string_ptr;
	    	uint32_t capabilities;
		    uint32_t video_mode_ptr;
		    uint16_t total_memory;
	
			// Vesa 2.0
			uint32_t oem_software_rev;
			char *oem_vendor_name;
			char *oem_product_name;
			char *oem_product_rev;
		} Info;

 

		typedef struct
		{
		    uint16_t mode_attributes;
		    uint8_t wina_attributes;
		    uint8_t winb_attributes;
		    uint16_t win_granularity;
		    uint16_t win_size;
		    uint16_t wina_segment;
		    uint16_t winb_segment;
		    uint32_t win_pos_func_ptr;
		    uint16_t bytes_per_scan_line;
		    uint16_t width;
		    uint16_t height;
		    uint8_t char_width;
		    uint8_t char_height;
		    uint8_t num_planes;
		    uint8_t bits_per_pixel;
		    uint8_t num_banks;
		    uint8_t memory_model_type;
		    uint8_t bank_size;
    		uint8_t num_image_pages;
    		uint8_t reserved1;
    		uint8_t red_mask_size;
    		uint8_t red_field_position;
    		uint8_t green_mask_size;
    		uint8_t green_field_position;
    		uint8_t blue_mask_size;
    		uint8_t blue_field_position;
    		uint8_t reserved_mask_size;
    		uint8_t reserved_mask_position;
    		uint8_t direct_color_mode_info;
    		uint32_t phys_base_ptr;
    		uint32_t offscreen_mem_ptr;
    		uint16_t offscreen_mem_size;
    		uint16_t lin_bytes_per_scan_line;
    		uint8_t bnk_num_image_pages;
   			uint8_t lin_num_image_pages;
    		uint8_t lin_red_mask_size;
    		uint8_t lin_red_field_position;
		    uint8_t lin_green_mask_size;
		    uint8_t lin_green_field_position;
		    uint8_t lin_blue_mask_size;
		    uint8_t lin_blue_field_position;
		    uint8_t lin_rsvd_mask_size;
		    uint8_t lin_rsvd_field_position;
		    uint32_t max_pixel_clock;
		    uint8_t reserved4[190];
		} ModeInfo;




		ModeInfo *getModeInfo();
		VesaDriver(unsigned, unsigned, unsigned);
		VesaDriver();
		~VesaDriver();
		
		bool Probe();

		unsigned getX();
		unsigned getY();
		unsigned getBpp();
		unsigned getBpsl();
		uint32_t getPixel(unsigned, unsigned);
		void drawPixel(unsigned, unsigned, uint32_t);
		bool setMode(unsigned, unsigned, unsigned);

		uint64_t Read(uint8_t *data, uint64_t size, uint64_t offset){ return 0; };
		uint64_t Write(uint8_t *data, uint64_t size, uint64_t offset){ return 0; };

		char *Memory;
};


#endif
