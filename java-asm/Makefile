# $NetBSD: Makefile,v 1.2 2004/05/10 19:39:54 poppnk Exp $
#

DISTNAME=		asm-1.4.2-bin
PKGNAME=		java-asm-1.4.2
WRKSRC=		${WRKDIR}/asm-1.4.2
CATEGORIES=		wip devel
MASTER_SITES=		http://download.forge.objectweb.org/asm/ \
				http://download.us.forge.objectweb.org/asm/
EXTRACT_SUFX=	.zip

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://asm.objectweb.org/
COMMENT=		Java bytecode manipulation framework

USE_BUILDLINK3=		yes

do-build:

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java/asm
	${INSTALL_DATA} ${WRKSRC}/lib/* ${PREFIX}/lib/java/asm/
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java-asm/
	${CP} -rf ${WRKSRC}/examples/* ${PREFIX}/share/examples/java-asm/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java-asm/
	${CP} -rf ${WRKSRC}/doc/javadoc/user/* ${PREFIX}/share/doc/java-asm/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
