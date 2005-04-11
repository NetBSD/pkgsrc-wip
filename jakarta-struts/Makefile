# $NetBSD: Makefile,v 1.2 2005/04/11 21:13:15 tvierling Exp $
#

DISTNAME=		jakarta-struts-1.1
CATEGORIES=		wip www
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
