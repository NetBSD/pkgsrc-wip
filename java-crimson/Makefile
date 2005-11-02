# $NetBSD: Makefile,v 1.4 2005/11/02 18:00:18 thomasklausner Exp $
#

DISTNAME=		crimson-1.1.3-bin
PKGNAME=	java-crimson-1.1.3
CATEGORIES=		textproc
MASTER_SITES=		http://xml.apache.org/dist/crimson/
EXTRACT_SUFX=		.zip

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://xml.apache.org/dist/crimson/
COMMENT=		XML parser for JAXP with DOM and SAX2.

WRKSRC=		${WRKDIR}/crimson-1.1.3

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/crimson.jar ${PREFIX}/share/classpath/

.include "../../mk/bsd.pkg.mk"
