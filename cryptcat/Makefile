# $NetBSD: Makefile,v 1.4 2012/09/24 18:26:55 asau Exp $
#

DISTNAME=		cryptcat-unix-1.2.1
CATEGORIES=		net security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cryptcat/}
EXTRACT_SUFX=		.tar

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://sourceforge.net/projects/cryptcat/
COMMENT=		Standard netcat enhanced with twofish encryption

USE_TOOLS+=		gmake
WRKSRC=		${WRKDIR}/unix
BUILD_TARGET=	${LOWER_OPSYS}

INSTALLATION_DIRS= 	share/doc/

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cryptcat ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cryptcat
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cryptcat/
	${INSTALL_DATA} ${WRKSRC}/README.cryptcat ${PREFIX}/share/doc/cryptcat/
	${INSTALL_DATA} ${WRKSRC}/Credits ${PREFIX}/share/doc/cryptcat/

.include "../../mk/bsd.pkg.mk"
