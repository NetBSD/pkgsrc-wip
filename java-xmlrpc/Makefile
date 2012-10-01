# $NetBSD: Makefile,v 1.7 2012/10/01 21:05:45 asau Exp $
#

DISTNAME=		xmlrpc-1.2-b1
PKGNAME=		java-xmlrpc-1.2
CATEGORIES=		net
MASTER_SITES=		http://apache.rediris.es/ws/xmlrpc/v1.2-b1/ \
			http://nagoya.apache.org/mirror/ws/xmlrpc/ \
			${MASTER_SITE_APACHE:=ws/xmlrpc/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://ws.apache.org/xmlrpc/
COMMENT=		Java implementation of XML-RPC


do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/classpath/
	${INSTALL_DATA} ${WRKSRC}/xmlrpc-1.2-b1.jar \
		${DESTDIR}${PREFIX}/share/classpath/xmlrpc-1.2-b1.jar
	${INSTALL_DATA} ${WRKSRC}/xmlrpc-1.2-b1-applet.jar \
		${DESTDIR}${PREFIX}/share/classpath/xmlrpc-1.2-b1-applet.jar
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/java-xmlrpc/
	${CP} -rf ${WRKSRC}/docs/apidocs/* \
		${DESTDIR}${PREFIX}/share/doc/java-xmlrpc/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
