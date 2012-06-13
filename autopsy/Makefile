# $NetBSD: Makefile,v 1.3 2012/06/13 08:00:49 othyro Exp $
#

VERSION=2.21
DISTNAME=		autopsy-${VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=autopsy/}

MAINTAINER=		oivulf@gmail.com
HOMEPAGE=		http://www.sleuthkit.org/
COMMENT=		Browser interface to sleuthkit
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

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
