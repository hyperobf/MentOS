#include "framebuffer.h"

/*
 * The current position in the terminal
 */
static size_t terminal_row;
static size_t terminal_column;
/*
 * The location in memory that the framebuffer is
 */
static uint16_t *framebuffer = (uint16_t*) 0x000B8000;

void framebuffer_write_cell(size_t i, 
		char c, 
		enum framebuffer_color fg, 
		enum framebuffer_color bg)
{
	uint8_t color = bg | fg << 4;
	uint16_t entry = (uint16_t) c | (uint16_t) color << 8;

	framebuffer[i] = entry;
}

void framebuffer_write_string(const char *data)
{
	for (size_t i = 0; i < strlen(data); i++)
	{
		if (data[i] == '\n')
		{
			terminal_row++;
			terminal_column = 0;
			continue;
		}
		if(terminal_row >= VGA_HEIGHT)
			framebuffer_scroll();
		const size_t index = terminal_row * VGA_WIDTH + terminal_column;
		framebuffer_write_cell(index, data[i], FB_BLACK, FB_LGRAY);
		if(++terminal_column == VGA_WIDTH)
		{
			terminal_column = 0;
			if(++terminal_row == VGA_HEIGHT)
			{
				framebuffer_scroll();
			}
		}
	}
}

void framebuffer_clear()
{
	terminal_row = 0;
	terminal_column = 0;
	for (size_t y = 0; y < VGA_HEIGHT; y++)
	{
		for(size_t x = 0; x < VGA_WIDTH; x++)
		{
			const size_t index = y * VGA_WIDTH + x;
			framebuffer_write_cell(index, ' ', FB_BLACK, FB_LGRAY);
		}
	}
}

void framebuffer_scroll()
{
	for (size_t y = 0; y < VGA_HEIGHT; y++)
	{
		for (size_t x = 0; x < VGA_WIDTH; x++)
		{
			framebuffer[y * VGA_WIDTH + x] = framebuffer[(y + 1) * VGA_WIDTH + x];
		}
	}
	terminal_row--;
}

void framebuffer_move_cursor(unsigned short pos)
{
	outb(FRAMEBUFFER_COMMAND_PORT, FRAMEBUFFER_HIGH_BYTE_CMD);
	outb(FRAMEBUFFER_DATA_PORT, ((pos >> 8) & 0x00FF));
	outb(FRAMEBUFFER_COMMAND_PORT, FRAMEBUFFER_LOW_BYTE_CMD);
	outb(FRAMEBUFFER_DATA_PORT, pos & 0x00FF);
}

void framebuffer_cursor_xy(size_t x, size_t y)
{
	framebuffer_move_cursor(y * VGA_WIDTH + x);
}
