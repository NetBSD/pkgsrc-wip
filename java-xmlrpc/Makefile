# $NetBSD: Makefile,v 1.3 2004/05/08 17:30:10 poppnk Exp $
#

DISTNAME=		xmlrpc-1.2-b1
PKGNAME=		java-xmlrpc-1.2
CATEGORIES=		wip
MASTER_SITES=		http://apache.rediris.es/ws/xmlrpc/v1.2-b1/ \
			http://nagoya.apache.org/mirror/ws/xmlrpc/ \
			http://www.apache.org/dist/ws/xmlrpc/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ws.apache.org/xmlrpc/
COMMENT=		Java implementation of XML-RPC

USE_BUILDLINK3=		yes

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/xmlrpc-1.2-b1.jar \
		${PREFIX}/share/classpath/xmlrpc-1.2-b1.jar
	${INSTALL_DATA} ${WRKSRC}/xmlrpc-1.2-b1-applet.jar \
		${PREFIX}/share/classpath/xmlrpc-1.2-b1-applet.jar
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java-xmlrpc/
	${CP} -rf ${WRKSRC}/docs/apidocs/* \
		${PREFIX}/share/doc/java-xmlrpc/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
