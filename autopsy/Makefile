# $NetBSD: Makefile,v 1.4 2012/09/24 16:56:40 asau Exp $
#

VERSION=2.21
DISTNAME=		autopsy-${VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=autopsy/}

MAINTAINER=		oivulf@gmail.com
HOMEPAGE=		http://www.sleuthkit.org/
COMMENT=		Browser interface to sleuthkit
LICENSE=		gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl
INSTALLATION_DIRS+=	share/autopsy/lib share/autopsy/pict

do-build:
	cd ${WRKSRC} && sh build ${PREFIX}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/autopsy ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/share/autopsy/lib
	${INSTALL_DATA} ${WRKSRC}/conf.pl ${WRKSRC}/global.css ${PREFIX}/share/autopsy/
	${INSTALL_DATA} ${WRKSRC}/pict/* ${PREFIX}/share/autopsy/pict
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${PREFIX}/${PKGMANDIR}/man1/

.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
