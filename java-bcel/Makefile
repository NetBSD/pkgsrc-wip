# $NetBSD: Makefile,v 1.1.1.1 2004/05/10 19:29:50 poppnk Exp $
#

DISTNAME=		bcel-5.1
PKGNAME=		java-bcel-5.1
CATEGORIES=		wip devel
MASTER_SITES=	http://apache.rediris.es/jakarta/bcel/binaries/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://jakarta.apache.org/bcel/
COMMENT=		ByteCode Engineering Library

USE_BUILDLINK3=		yes

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/bcel-5.1.jar ${PREFIX}/lib/java/bcel.jar
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java-bcel/
	${CP} -rf ${WRKSRC}/docs/* ${PREFIX}/share/doc/java-bcel/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
