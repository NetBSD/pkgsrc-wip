# $NetBSD: Makefile,v 1.2 2009/02/19 16:13:38 fulviociriaco Exp $
#

VERSION=2.21
DISTNAME=		autopsy-${VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=autopsy/}

MAINTAINER=		oivulf@gmail.com
HOMEPAGE=		http://www.sleuthkit.org/
COMMENT=		Browser interface to sleuthkit

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl

do-build:
	cd ${WRKSRC} && sh build ${PREFIX}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/autopsy ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/autopsy/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/autopsy/pict
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/share/autopsy/lib
	${INSTALL_DATA} ${WRKSRC}/conf.pl ${WRKSRC}/global.css ${PREFIX}/share/autopsy/
	${INSTALL_DATA} ${WRKSRC}/pict/* ${PREFIX}/share/autopsy/pict
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${PREFIX}/${PKGMANDIR}/man1/

.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
