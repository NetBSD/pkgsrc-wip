# $NetBSD: Makefile,v 1.5 2007/01/03 14:38:15 shattered Exp $
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

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/memgrep.h ${PREFIX}/include/
	${INSTALL_PROGRAM} ${WRKSRC}/memgrep ${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/libmemgrep.* ${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/heaplist.so ${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
