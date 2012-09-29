# $NetBSD: Makefile,v 1.9 2012/09/29 17:07:40 asau Exp $
#

DISTNAME=		itext-1.3
PKGNAME=		java-itext-1.3
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=itext/
EXTRACT_SUFX=		.jar

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.lowagie.com/iText/
COMMENT=		Java classes to generate PDF files on the fly

WRKSRC=			${WRKDIR}

do-extract:

do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar ${DESTDIR}${PREFIX}/lib/java/itext.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
