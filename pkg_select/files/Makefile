PROG=	pkg_select
SRCS=	main.c parsedirs.c tools.c file.c more.c listmgt.c \
		pkg_adm.c pkg_info.c curses_helpers.c makefile.c

WARNS=	3

CFLAGS+=	-g
CFLAGS+=	-DPKGSRCBASE=\"/usr/pkgsrc\" -DPKGDB=\"/var/db/pkg\"

LDADD=	-lcurses
DPADD=	${LIBCURSES}

.include <bsd.prog.mk>
