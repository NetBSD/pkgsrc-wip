PROG=	pkg_select
SRCS=	main.c parsedirs.c tools.c file.c more.c listmgt.c \
		pkg_adm.c pkg_info.c curses_helpers.c makefile.c pkgsrc.c \
		install_many.c conf.c ftpio.c prefs.c live.c \
		curses_input.c

WARNS=	3

CFLAGS+=	-g -I.
CFLAGS+=	-DPKGSRCBASE=\"/usr/pkgsrc\" -DPKGDB=\"/var/db/pkg\"
CFLAGS+=	-DMAKE=\"/usr/bin/make\"
CFLAGS+=	-DCONFPATH=\"/usr/pkg/etc/pkg_select.conf\"
CFLAGS+=	-DMIRRORS=\"/usr/pkg/share/pkg_select\"


LDADD=	-lcurses
DPADD=	${LIBCURSES}

.include <bsd.prog.mk>
