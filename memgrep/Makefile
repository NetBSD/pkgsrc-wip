# $NetBSD: Makefile,v 1.6 2012/10/03 14:07:46 asau Exp $
#

DISTNAME=		memgrep-0.8.0
CATEGORIES=		devel
MASTER_SITES=		http://www.hick.org/code/skape/memgrep/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.hick.org/code.html
COMMENT=		Tool to modify applications on-the-fly

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
ONLY_FOR_PLATFORM=	Linux-*-*

INSTALLATION_DIRS=	bin lib include

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/memgrep.h ${DESTDIR}${PREFIX}/include/
	${INSTALL_PROGRAM} ${WRKSRC}/memgrep ${DESTDIR}${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/libmemgrep.* ${DESTDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/heaplist.so ${DESTDIR}${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
