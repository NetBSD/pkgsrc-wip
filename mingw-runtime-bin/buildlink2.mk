# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/11/29 18:20:43 mpasternak Exp $
#
# This Makefile fragment is included by packages that use mingw-runtime-bin.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(MINGW_RUNTIME_BIN_BUILDLINK2_MK)
MINGW_RUNTIME_BIN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			mingw-runtime-bin
BUILDLINK_DEPENDS.mingw-runtime-bin?=		mingw-runtime-bin>=3.2
BUILDLINK_PKGSRCDIR.mingw-runtime-bin?=		../../wip/mingw-runtime-bin

EVAL_PREFIX+=	BUILDLINK_PREFIX.mingw-runtime-bin=mingw-runtime-bin
BUILDLINK_PREFIX.mingw-runtime-bin_DEFAULT=	${CROSSBASE}/i586-mingw
BUILDLINK_FILES.mingw-runtime-bin+=	\
	include/assert.h include/conio.h include/ctype.h \
	include/dir.h include/direct.h include/dirent.h include/dos.h \
	include/errno.h include/excpt.h include/fcntl.h include/fenv.h \
	include/float.h include/getopt.h include/gmon.h include/inttypes.h \
	include/io.h include/limits.h include/locale.h include/malloc.h \
	include/math.h include/mbctype.h include/mbstring.h include/mem.h \
	include/memory.h include/process.h include/profil.h \
	include/profile.h include/search.h include/setjmp.h include/share.h \
	include/signal.h include/stdarg.h include/stddef.h include/stdint.h \
	include/stdio.h include/stdlib.h include/string.h include/strings.h \
	include/sys/fcntl.h include/sys/file.h include/sys/locking.h \
	include/sys/param.h include/sys/stat.h include/sys/time.h \
	include/sys/timeb.h include/sys/types.h include/sys/unistd.h \
	include/sys/utime.h include/tchar.h include/time.h include/unistd.h \
	include/utime.h include/values.h include/varargs.h include/wchar.h \
	include/wctype.h include/_mingw.h lib/binmode.o lib/crt1.o \
	lib/crt2.o lib/crtmt.o lib/crtst.o lib/CRT_fp10.o lib/CRT_fp8.o \
	lib/CRT_noglob.o lib/dllcrt1.o lib/dllcrt2.o lib/gcrt1.o lib/gcrt2.o \
	lib/libcoldname.a lib/libcrtdll.a lib/libgmon.a lib/libm.a \
	lib/libmingw32.a lib/libmingwex.a lib/libmingwthrd.a \
	lib/libmoldname.a lib/libmoldnamed.a lib/libmsvcr70.a \
	lib/libmsvcr70d.a lib/libmsvcrt.a lib/libmsvcr71.a lib/libmsvcr71d.a \
	lib/libmsvcrtd.a lib/txtmode.o

BUILDLINK_TARGETS+=	mingw-runtime-bin-buildlink

mingw-runtime-bin-buildlink: _BUILDLINK_USE

.endif	# MINGW_RUNTIME_BIN_BUILDLINK2_MK
