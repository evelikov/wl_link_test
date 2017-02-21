#include <string.h>
#include <wayland-util.h>
#include <wayland-client.h>
#include <wayland-server.h>


int
export_main(void)
{
    struct wl_list list;

    wl_list_init(&list);

    struct wl_array array;

    memset(&array, 0x57, sizeof array);

    wl_array_init(&array);
    return 0;
}

