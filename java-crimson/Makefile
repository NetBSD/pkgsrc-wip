# $NetBSD: Makefile,v 1.5 2012/10/01 20:26:04 asau Exp $
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

INSTALLATION_DIRS=	share/classpath

do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/crimson.jar ${DESTDIR}${PREFIX}/share/classpath/

.include "../../mk/bsd.pkg.mk"
