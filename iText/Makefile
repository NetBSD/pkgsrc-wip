# $NetBSD: Makefile,v 1.4 2004/07/18 15:50:22 ppostma Exp $
#

DISTNAME=		iText
PKGNAME=		iText-1.02
CATEGORIES=		devel
MASTER_SITES=		http://itext.sourceforge.net/downloads/
EXTRACT_SUFX=		.jar

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://itext.sourceforge.net/
COMMENT=		Java classes to generate PDF files on the fly

WRKSRC=			${WRKDIR}
USE_BUILDLINK3=		yes

do-extract:

do-build:

do-install:
		${INSTALL_DATA} ${DISTDIR}/iText.jar ${PREFIX}/lib/iText.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
