AM_CPPFLAGS = $(WL_CFLAGS)

bin_PROGRAMS = wl-link-test
wl_link_test_SOURCES = main.c
wl_link_test_LDADD = $(WL_LIBS)

lib_LTLIBRARIES = libwl-link-test.la
libwl_link_test_la_SOURCES = lib.c
libwl_link_test_la_LIBADD = $(WL_LIBS)
libwl_link_test_la_LDFLAGS = \
	-shared \
	-no-version-info \
	-no-undefined \
	-Wl,--no-undefined

bin_PROGRAMS = wl-dl-test
wl_dl_test_SOURCES = dltest.c
wl_dl_test_LDADD = -ldl
