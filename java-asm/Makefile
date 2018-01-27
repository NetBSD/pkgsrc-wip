# $NetBSD: Makefile,v 1.6 2012/11/25 23:32:22 othyro Exp $
#

DISTNAME=	asm-1.4.2-bin
PKGNAME=	java-asm-1.4.2
WRKSRC=		${WRKDIR}/asm-1.4.2
CATEGORIES=	devel
MASTER_SITES=	http://download.forge.objectweb.org/asm/ \
		http://download.us.forge.objectweb.org/asm/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://asm.objectweb.org/
COMMENT=	Java bytecode manipulation framework

do-build:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java/asm
	${INSTALL_DATA} ${WRKSRC}/lib/* ${DESTDIR}${PREFIX}/lib/java/asm/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/java-asm/
	${CP} -rf ${WRKSRC}/examples/* ${DESTDIR}${PREFIX}/share/examples/java-asm/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/java-asm/
	${CP} -rf ${WRKSRC}/doc/javadoc/user/* ${DESTDIR}${PREFIX}/share/doc/java-asm/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
