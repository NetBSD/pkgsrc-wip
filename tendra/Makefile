# $NetBSD: Makefile,v 1.1.1.1 2003/04/29 09:22:27 thomasklausner Exp $

DISTNAME=	TenDRA-4.1.2
PKGNAME=	tendra-4.1.2
CATEGORIES=	devel
MASTER_SITES=	http://www.info.uni-karlsruhe.de/~andf/download/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.info.uni-karlsruhe.de/~andf/tendra.htm
COMMENT=	Multi-targetted C and C++ compiler

pre-patch:
	${MKDIR} ${WRKSRC}/src/installers/80x86
	${MKDIR} ${WRKSRC}/src/lib/env/netbsd/common/80x86
	${MKDIR} ${WRKSRC}/src/lib/machines/netbsd/80x86/include
	${MKDIR} ${WRKSRC}/src/lib/machines/netbsd/80x86/startup
	${MKDIR} ${WRKSRC}/src/lib/machines/netbsd/80x86/tokens

do-build:
	${MKDIR} ${WRKSRC}/build
	cd ${WRKSRC}; ${SETENV} PREFIX=${PREFIX} ./INSTALL

.include "../../mk/bsd.pkg.mk"
