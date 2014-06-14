/* Os42 Kernel */

#include <stdint.h>

#include <stdio.h>
#include <vga.h>

/* Entry point for the kernel */
void kernel_main() {
	
	uint8_t byte;
	uint8_t status;
	
	vga_init();
	vga_set_color(COLOR_LIGHT_CYAN, COLOR_BLACK);
	
	puts(	"                                                                                "
			"        OOOOOOOOO                             444444444   222222222222222       "
			"      OO:::::::::OO                          4::::::::4  2:::::::::::::::22     "
			"    OO:::::::::::::OO                       4:::::::::4  2::::::222222:::::2    "
			"   O:::::::OOO:::::::O                     4::::44::::4  2222222     2:::::2    "
			"   O::::::O   O::::::O    ssssssssss      4::::4 4::::4              2:::::2    "
			"   O:::::O     O:::::O  ss::::::::::s    4::::4  4::::4              2:::::2    "
			"   O:::::O     O:::::Oss:::::::::::::s  4::::4   4::::4           2222::::2     "
			"   O:::::O     O:::::Os::::::ssss:::::s4::::444444::::444    22222::::::22      "
			"   O:::::O     O:::::O s:::::s  ssssss 4::::::::::::::::4  22::::::::222        "
			"   O:::::O     O:::::O   s::::::s      4444444444:::::444 2:::::22222           "
			"   O:::::O     O:::::O      s::::::s             4::::4  2:::::2                "
			"   O::::::O   O::::::Ossssss   s:::::s           4::::4  2:::::2                "
			"   O:::::::OOO:::::::Os:::::ssss::::::s          4::::4  2:::::2       222222   "
			"    OO:::::::::::::OO s::::::::::::::s         44::::::442::::::2222222:::::2   "
			"      OO:::::::::OO    s:::::::::::ss          4::::::::42::::::::::::::::::2   "
			"        OOOOOOOOO       sssssssssss            444444444422222222222222222222   "
			"                                                                                ");
	vga_set_fg(COLOR_YELLOW);		
	puts(	"                       /\\          | |  | |                                     "
			"                      /  \\    _ __ | |_ | |__   _   _  _ __                     "
			"                     / /\\ \\  | '__|| __|| '_ \\ | | | || '__|                    "
			"                    / ____ \\ | |   | |_ | | | || |_| || |                       "
			"                   /_/    \\_\\|_|    \\__||_| |_| \\__,_||_|                       \n");
	vga_set_fg(COLOR_LIGHT_GREY);
	//puts("Starting Up...");
	
	while (1) {
		do {
			status = inb(0x64);
		} while (!(status & 1));
		byte = inb(0x60);
		puth(byte);
		putc(' ');
	}
}
