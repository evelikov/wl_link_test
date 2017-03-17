#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


struct wl_list {
        /** Previous list element */
        struct wl_list *prev;
        /** Next list element */
        struct wl_list *next;
};

void (*wl_list_init)(struct wl_list *list);

struct wl_array {
        /** Array size */
        size_t size;
        /** Allocated space */
        size_t alloc;
        /** Array data */
        void *data;
};

void
(*wl_array_init)(struct wl_array *array);

static void
test(void)
{
    struct wl_list list;

    wl_list_init(&list);

    struct wl_array array;

    memset(&array, 0x57, sizeof array);

    wl_array_init(&array);
}

static void
get_symbols_n_test(const char *fname)
{
    void *handle;

    handle = dlopen(fname, RTLD_NOW | RTLD_LOCAL);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

    wl_list_init = dlsym(handle, "wl_list_init");
    wl_array_init = dlsym(handle, "wl_array_init");
    test();
    fprintf(stdout, "SUCCESS: %s\n", fname);
    dlclose(handle);
}

int
main(void)
{
    fprintf(stdout, "LD_LIBRARY_PATH to the correct libraries, and check with LD_DEBUG=libs\n");
    get_symbols_n_test("libwayland-client.so");
    get_symbols_n_test("libwayland-server.so");
    return 0;
}
