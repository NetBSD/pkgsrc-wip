# $NetBSD: Makefile,v 1.9 2008/01/03 23:08:57 rillig Exp $
#

DISTNAME=		pizza-1.1
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pizzacompiler/}
EXTRACT_SUFX=		.jar

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://pizzacompiler.sourceforge.net/
COMMENT=		Pizza language is an extension to Java

WRKSRC=			${WRKDIR}
AUTO_MKDIRS=		yes
USE_TOOLS+=		printf

do-build:
	printf "#! ${SH}\\nexec ${JAVA_BINPREFIX}-java -jar ${PREFIX}/lib/java/${DISTNAME}.jar \"\$$@\"\\n" > ${WRKSRC}/pizza.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pizza.sh ${PREFIX}/bin/pizza
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${PREFIX}/lib/java/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
