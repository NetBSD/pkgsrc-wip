# $NetBSD: Makefile,v 1.1.1.1 2004/11/14 22:33:15 poppnk Exp $
#

DISTNAME=		crimson-1.1.3-bin
PKGNAME=	java-crimson-1.1.3
CATEGORIES=		wip
MASTER_SITES=		http://xml.apache.org/dist/crimson/
EXTRACT_SUFX=		.zip

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://xml.apache.org/dist/crimson/
COMMENT=		XML parser for JAXP with DOM and SAX2.

WRKSRC=		${WRKDIR}/crimson-1.1.3
USE_BUILDLINK3=		yes

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/crimson.jar ${PREFIX}/share/classpath/

.include "../../mk/bsd.pkg.mk"
