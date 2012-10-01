# $NetBSD: Makefile,v 1.5 2012/10/01 20:23:09 asau Exp $
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
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/bcel-5.1.jar ${DESTDIR}${PREFIX}/lib/java/bcel.jar
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/java-bcel/
	${CP} -rf ${WRKSRC}/docs/* ${DESTDIR}${PREFIX}/share/doc/java-bcel/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
