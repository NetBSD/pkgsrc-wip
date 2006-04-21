# $NetBSD: Makefile,v 1.1.1.1 2006/04/21 10:08:29 poppnk Exp $
#

DISTNAME=		cryptcat-unix-1.2.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cryptcat/}
EXTRACT_SUFX=		.tar

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://farm9.org/Cryptcat/
COMMENT=		Standard netcat enhanced with twofish encryption.

USE_TOOLS+=		gmake
WRKSRC=		${WRKDIR}/unix
BUILD_TARGET=	${LOWER_OPSYS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cryptcat ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cryptcat
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cryptcat/
	${INSTALL_DATA} ${WRKSRC}/README.cryptcat ${PREFIX}/share/doc/cryptcat/
	${INSTALL_DATA} ${WRKSRC}/Credits ${PREFIX}/share/doc/cryptcat/

.include "../../mk/bsd.pkg.mk"
