# $NetBSD: Makefile,v 1.2 2004/12/02 16:39:02 thomasklausner Exp $
#

DISTNAME=		libvg-0.2.0
CATEGORIES=		wip devel
MASTER_SITES=		http://www.7a69ezine.org/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.7a69ezine.org/project/libvg/
COMMENT=		High-level ptrace library

WRKSRC=		${WRKDIR}/libvg/src
USE_BUILDLINK3=		yes
BUILD_TARGET= ${LOWER_OPSYS}
ONLY_FOR_PLATFORM= FreeBSD-*-* NetBSD-*-* OpenBSD-*-* Linux-*-*

do-install:
	${INSTALL_LIB} ${WRKSRC}/libvg.so ${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libvg.a  ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
