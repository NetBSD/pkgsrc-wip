# $NetBSD: Makefile,v 1.5 2013/09/03 17:40:00 shattered Exp $
#

VERSION=		2.21
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
INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && sh build ${DESTDIR}${PREFIX}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/autopsy ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/share/autopsy/lib
	${INSTALL_DATA} ${WRKSRC}/conf.pl ${WRKSRC}/global.css ${DESTDIR}${PREFIX}/share/autopsy/
	${INSTALL_DATA} ${WRKSRC}/pict/* ${DESTDIR}${PREFIX}/share/autopsy/pict
	${INSTALL_MAN} ${WRKSRC}/man/man1/* ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
