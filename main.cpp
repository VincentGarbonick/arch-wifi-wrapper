#include <FL/Fl.H>
#include "./functionality/draw.h"

int main(int argc, char **argv) 
{	
	if(host_has_nmcli())
	{
		draw_main_app();
	}
	else 
	{
		draw_no_nmcli_screen();
	}
	
	return Fl::run();
}