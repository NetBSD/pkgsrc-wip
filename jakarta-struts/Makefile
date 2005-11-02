# $NetBSD: Makefile,v 1.3 2005/11/02 18:00:17 thomasklausner Exp $
#

DISTNAME=		jakarta-struts-1.1
CATEGORIES=		www
MASTER_SITES=		http://apache.rediris.es/jakarta/struts/binaries/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://apache.rediris.es/jakarta/struts/binaries/
COMMENT=		struts is struts xD


do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java/jakarta-struts/
	${INSTALL_DATA} ${WRKSRC}/lib/* \
		${PREFIX}/lib/java/jakarta-struts/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
