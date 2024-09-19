# $NetBSD: Makefile,v 1.8 2012/11/25 23:32:24 othyro Exp $
#

DISTNAME=		xmlrpc-1.2-b1
PKGNAME=		java-xmlrpc-1.2
CATEGORIES=		net
MASTER_SITES=		http://apache.rediris.es/ws/xmlrpc/v1.2-b1/ \
			http://nagoya.apache.org/mirror/ws/xmlrpc/ \
			${MASTER_SITE_APACHE:=ws/xmlrpc/}
LICENSE=		apache-2.0

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://ws.apache.org/xmlrpc/
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
