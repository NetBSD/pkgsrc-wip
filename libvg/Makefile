# $NetBSD: Makefile,v 1.5 2012/10/03 08:34:53 asau Exp $
#

DISTNAME=		libvg-0.2.0
CATEGORIES=		devel
MASTER_SITES=		http://www.7a69ezine.org/download/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.7a69ezine.org/project/libvg/
COMMENT=		High-level ptrace library

WRKSRC=		${WRKDIR}/libvg/src
BUILD_TARGET= ${LOWER_OPSYS}
ONLY_FOR_PLATFORM= FreeBSD-*-* NetBSD-*-* OpenBSD-*-* Linux-*-*

INSTALLATION_DIRS=	lib include

do-install:
	${INSTALL_LIB} ${WRKSRC}/libvg.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libvg.a  ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/* ${DESTDIR}${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
