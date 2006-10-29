# $NetBSD: Makefile,v 1.3 2006/10/29 08:32:41 shattered Exp $

DISTNAME=		crafty-20.14
CATEGORIES=		games
MASTER_SITES=		ftp://ftp.cis.uab.edu/pub/hyatt/source/ \
			ftp://ftp.cis.uab.edu/pub/hyatt/pgn/
DISTFILES=		${CRAFTY_DISTFILES}
DISTFILES+=		${CRAFTY_STARTPGN}

MAINTAINER=		mrohrer@users.sourceforge.net
COMMENT=		Chess engine


CRAFTY_DISTFILES=	crafty-20.14.zip
CRAFTY_STARTPGN=	start.pgn
EXTRACT_ONLY=		${CRAFTY_DISTFILES}

DOCDIR=			${PREFIX}/share/crafty
BOOKDIR=		.

CRAFTY_OPTS= -DTBDIR=\"${PREFIX}/share/crafty\"
CRAFTY_OPTS+= -DBOOKDIR=\"${BOOKDIR}\"

MAKE_ENV+=		opt=${CRAFTY_OPTS:Q}

CRAFTYRC=		${WRKSRC}/.craftyrc
INSTALLATION_DIRS=	bin

.include "../../mk/bsd.prefs.mk"

# build according to OS.  This list is not very thorough yet
.if !empty(MACHINE_PLATFORM:MNetBSD-*-i386)
BUILD_TARGET=		netbsd-i386
.elif !empty(MACHINE_PLATFORM:MNetBSD-*-sparc)
BUILD_TARGET=		netbsd-sparc
.elif !empty(MACHINE_PLATFORM:MNetBSD-*-*)
BUILD_TARGET=		netbsd
.elif !empty(MACHINE_PLATFORM:MLinux-*-i386)
BUILD_TARGET=		linux
.elif !empty(MACHINE_PLATFORM:MSunOS-*-*)
BUILD_TARGET=		solaris-gcc
.endif

post-extract:
	${CP} ${DISTDIR}/${CRAFTY_STARTPGN} ${WRKSRC}

# this is to remove -O3 from crafty's makefile and use the systems -O?
post-patch:
	cd ${WRKSRC}; for file in Makefile; do 			\
		${SED} "s| -O3||g" $${file} >> $${file}.fixed;	\
		${MV} $${file}.fixed $${file};			\
	done

post-build:
	${RM} -f ${CRAFTYRC}
	${ECHO} "books create ${CRAFTY_STARTPGN} 60" > ${CRAFTYRC}
	${ECHO} "quit" >> ${CRAFTYRC}
	cd ${WRKSRC} && ${WRKSRC}/crafty bookpath=.

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/crafty ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/books.bin ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
