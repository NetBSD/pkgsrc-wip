# $NetBSD: Makefile,v 1.1.1.1 2004/05/08 18:11:50 poppnk Exp $
#

DISTNAME=		jakarta-struts-1.1
CATEGORIES=		wip www
MASTER_SITES=		http://apache.rediris.es/jakarta/struts/binaries/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://apache.rediris.es/jakarta/struts/binaries/
COMMENT=		struts is struts xD

USE_BUILDLINK3=		yes

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java/jakarta-struts/
	${INSTALL_DATA} ${WRKSRC}/lib/* \
		${PREFIX}/lib/java/jakarta-struts/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
