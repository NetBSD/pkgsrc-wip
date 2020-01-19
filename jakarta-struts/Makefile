# $NetBSD: Makefile,v 1.7 2012/11/25 23:32:21 othyro Exp $
#

DISTNAME=		jakarta-struts-1.1
CATEGORIES=		www
MASTER_SITES=		http://archive.apache.org/dist/struts/struts-1.1/
LICENSE=		apache-2.0

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://archive.apache.org/dist/struts/struts-1.1/
COMMENT=		Struts is struts xD


do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java/jakarta-struts/
	${INSTALL_DATA} ${DESTDIR}${WRKSRC}/lib/* \
		${PREFIX}/lib/java/jakarta-struts/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
