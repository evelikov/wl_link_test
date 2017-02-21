dnl Process this file with autoconf to create configure.

AC_PREREQ([2.60])

AC_INIT([wl_link_test], [1.0])
AC_CONFIG_AUX_DIR([bin])
AC_CONFIG_MACRO_DIR([m4])
AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE([foreign])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])],
    [AC_SUBST([AM_DEFAULT_VERBOSITY], [1])])

dnl Check for progs
AC_PROG_CC
AC_PROG_INSTALL

LT_PREREQ([2.2])
LT_INIT([disable-static])

PKG_PROG_PKG_CONFIG()
PKG_CHECK_MODULES([WL], [wayland-client wayland-server])

CFLAGS="$CFLAGS -Wall -Wextra -std=c99"

AC_CONFIG_FILES([
	Makefile
])

AC_OUTPUT
