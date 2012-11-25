# $NetBSD: Makefile,v 1.5 2012/11/25 23:32:09 othyro Exp $
#

DISTNAME=		cryptcat-unix-1.2.1
CATEGORIES=		net security
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cryptcat/}
EXTRACT_SUFX=		.tar

MAINTAINER=		pkgsrc-users@NetBSD.org
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
