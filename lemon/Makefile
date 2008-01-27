# $NetBSD: Makefile,v 1.5 2008/01/27 14:10:53 airhead Exp $

PKGNAME=	lemon-1.0
DISTNAME=	sqlite-3.5.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.hwaci.com/sw/sqlite/ \
		http://www.sqlite.org/

MAINTAINER=	airhead@users.sf.net
HOMEPAGE=	http://www.hwaci.com/sw/lemon/
COMMENT=	Simple LALR(1) parser generator

CONFIGURE=			no
CHECK_PORTABILITY_SKIP+=	configure

do-build: lemon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tool/lemon ${PREFIX}/bin
	# This probably should be fixed by patching the searchpath
	# and putting it in ${PREFIX}/share/lemon or sth
	${INSTALL_DATA} ${WRKSRC}/tool/lempar.c ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"

# So the WRKSRC is known at this stage
lemon: ${WRKSRC}/tool/lemon

${WRKSRC}/tool/lemon: ${WRKSRC}/tool/lemon.c
	cd ${WRKSRC}/tool; \
	${CC} ${CFLAGS} lemon.c -o lemon
