# $NetBSD: Makefile,v 1.6 2012/09/29 17:09:46 asau Exp $
#

DISTNAME=		iTextXML
PKGNAME=		iTextXML-1.02
CATEGORIES=		textproc
MASTER_SITES=		http://itext.sourceforge.net/downloads/
EXTRACT_SUFX=		.jar

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.lowagie.com/iText/
COMMENT=		Java classes to generate and parse XML files

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	lib

do-extract:

do-build:

do-install:
		${INSTALL_DATA} ${DISTDIR}/iTextXML.jar ${DESTDIR}${PREFIX}/lib/iTextXML.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
