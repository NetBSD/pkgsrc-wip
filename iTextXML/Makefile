# $NetBSD: Makefile,v 1.1.1.1 2004/02/21 12:01:47 poppnk Exp $
#

DISTNAME=		iTextXML
PKGNAME=		iTextXML-1.02
CATEGORIES=		wip
MASTER_SITES=		http://itext.sourceforge.net/downloads/
EXTRACT_SUFX=		.jar

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://itext.sourceforge.net/
COMMENT=		Java classes to generate and parse XML files

WRKSRC=			${WRKDIR}
USE_BUILDLINK2=		yes

do-extract:

do-build:

do-install:
		${INSTALL_DATA} ${DISTDIR}/iTextXML.jar ${PREFIX}/lib/iTextXML.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
