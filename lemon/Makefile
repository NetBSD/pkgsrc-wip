# $NetBSD: Makefile,v 1.2 2007/09/10 23:20:51 airhead Exp $

PKGNAME=	lemon-1.0
DISTNAME=	lemon.c
EXTRACT_SUFX=
WRKSRC=		${WRKDIR}
CATEGORIES=	wip devel
MASTER_SITES=	http://www.sqlite.org/cvstrac/getfile/sqlite/tool/
DISTFILES=	lemon.c lempar.c

MAINTAINER=	airhead@users.sf.net
HOMEPAGE=	http://www.hwaci.com/sw/lemon/
COMMENT=	Simple LALR(1) parser generator

do-build: lemon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lemon ${PREFIX}/bin
	# This probably should be fixed by patching the searchpath
	# and putting it in ${PREFIX}/share/lemon or sth
	${INSTALL_DATA} ${WRKSRC}/lempar.c ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"

# So the WRKDIR is known
lemon: ${WRKDIR}/lemon

${WRKSRC}/lemon: ${WRKSRC}/lemon.c
	cd ${WRKSRC}; \
	${CC} ${CFLAGS} lemon.c -o lemon
