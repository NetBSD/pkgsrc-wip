# $NetBSD: Makefile,v 1.6 2012/11/25 23:32:23 othyro Exp $
#

DISTNAME=		bcel-5.2
PKGNAME=		java-bcel-5.2
CATEGORIES=		devel
MASTER_SITES=		http://archive.apache.org/dist/commons/bcel/binaries/
LICENSE=		apache-2.0

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://jakarta.apache.org/bcel/
COMMENT=		ByteCode Engineering Library

NO_BUILD=		yes

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/bcel-5.2.jar ${DESTDIR}${PREFIX}/lib/java/bcel.jar
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/java-bcel/
	${CP} -rf ${WRKSRC}/docs/* ${DESTDIR}${PREFIX}/share/doc/java-bcel/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
