# $NetBSD: Makefile,v 1.5 2006/07/02 19:04:34 shattered Exp $
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

do-extract:

do-build:

do-install:
		${INSTALL_DATA} ${DISTDIR}/iTextXML.jar ${PREFIX}/lib/iTextXML.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
