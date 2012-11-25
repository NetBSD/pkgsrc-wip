# $NetBSD: Makefile,v 1.7 2012/11/25 23:32:20 othyro Exp $
#

DISTNAME=		iTextXML
PKGNAME=		iTextXML-1.02
CATEGORIES=		textproc
MASTER_SITES=		http://itext.sourceforge.net/downloads/
EXTRACT_SUFX=		.jar

MAINTAINER=		pkgsrc-users@NetBSD.org
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
