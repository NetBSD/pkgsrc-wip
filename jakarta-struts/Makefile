# $NetBSD: Makefile,v 1.5 2012/09/30 12:09:49 asau Exp $
#

DISTNAME=		jakarta-struts-1.1
CATEGORIES=		www
MASTER_SITES=		http://archive.apache.org/dist/struts/struts-1.1/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://archive.apache.org/dist/struts/struts-1.1/
COMMENT=		struts is struts xD


do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java/jakarta-struts/
	${INSTALL_DATA} ${DESTDIR}${WRKSRC}/lib/* \
		${PREFIX}/lib/java/jakarta-struts/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
