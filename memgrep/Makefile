# $NetBSD: Makefile,v 1.2 2005/06/13 00:09:10 kristerw Exp $
#

DISTNAME=		memgrep-0.8.0
CATEGORIES=		wip devel
MASTER_SITES=		http://www.hick.org/code/skape/memgrep/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.hick.org/code/skape/memgrep/
COMMENT=		Tool to modify applications on-the-fly

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/memgrep.h ${PREFIX}/include/
	${INSTALL_PROGRAM} ${WRKSRC}/memgrep ${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/libmemgrep.* ${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/heaplist.so ${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
