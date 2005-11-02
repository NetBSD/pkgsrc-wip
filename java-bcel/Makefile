# $NetBSD: Makefile,v 1.4 2005/11/02 18:00:18 thomasklausner Exp $
#

DISTNAME=		bcel-5.1
PKGNAME=		java-bcel-5.1
CATEGORIES=		devel
MASTER_SITES=	http://apache.rediris.es/jakarta/bcel/binaries/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://jakarta.apache.org/bcel/
COMMENT=		ByteCode Engineering Library

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/bcel-5.1.jar ${PREFIX}/lib/java/bcel.jar
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java-bcel/
	${CP} -rf ${WRKSRC}/docs/* ${PREFIX}/share/doc/java-bcel/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
