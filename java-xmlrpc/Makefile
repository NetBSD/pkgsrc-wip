# $NetBSD: Makefile,v 1.1.1.1 2004/03/08 16:38:02 poppnk Exp $
#

DISTNAME=		xmlrpc-1.2-b1
PKGNAME=		xmlrpc-1.2
CATEGORIES=		wip
MASTER_SITES=		http://apache.rediris.es/ws/xmlrpc/v1.2-b1/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ws.apache.org/xmlrpc/
COMMENT=		Java implementation of XML-RPC

USE_BUILDLINK2=		yes

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/xmlrpc-1.2-b1.jar \
		${PREFIX}/share/classpath/xmlrpc-1.2-b1.jar
	${INSTALL_DATA} ${WRKSRC}/xmlrpc-1.2-b1-applet.jar \
		${PREFIX}/share/classpath/xmlrpc-1.2-b1-applet.jar

.include "../../mk/bsd.pkg.mk"
