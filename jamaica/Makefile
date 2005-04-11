# $NetBSD: Makefile,v 1.2 2005/04/11 21:13:15 tvierling Exp $
#

DISTNAME=		jamaica-1.0
WRKSRC=		${WRKDIR}/
CATEGORIES=		wip lang
MASTER_SITES=		http://www.judoscript.com/store/
EXTRACT_SUFX=		.zip

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://www.judoscript.com/articles/jamaica.html
COMMENT=		JVM Macro Assembler language

DEPENDS+=		java-bcel>=5.1:../../wip/java-bcel
DEPENDS+=		java-asm>=1.4.2:../../wip/java-asm


do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/jamaica.jar ${PREFIX}/lib/java/
	${ECHO} export CLASSPATH=${PREFIX}/lib/java/bcel.jar:\$$CLASSPATH > \
		${PREFIX}/bin/jamaica
	${ECHO} export CLASSPATH=${PREFIX}/lib/java/asm/asm.jar:\$$CLASSPATH >> \
		${PREFIX}/bin/jamaica
	${ECHO} java -jar ${PREFIX}/lib/java/jamaica.jar \$$@ >> ${PREFIX}/bin/jamaica
	${CHMOD} +x ${PREFIX}/bin/jamaica
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/jamaica/
	${INSTALL_DATA} ${WRKSRC}/test/* \
			${PREFIX}/share/examples/jamaica/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
