# $NetBSD: Makefile,v 1.1.1.1 2005/03/15 00:32:43 poppnk Exp $
#

DISTNAME=		memgrep-0.8.0
CATEGORIES=		wip devel
MASTER_SITES=		http://www.hick.org/code/skape/memgrep/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.hick.org/code/skape/memgrep/
COMMENT=		Tool to modify applications on-the-fly

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/memgrep.h ${PREFIX}/include/
	${INSTALL_PROGRAM} ${WRKSRC}/memgrep ${PREFIX}/bin/
	${INSTALL_LIB} ${WRKSRC}/libmemgrep.* ${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/heaplist.so ${PREFIX}/lib/

.include "../../mk/bsd.pkg.mk"
