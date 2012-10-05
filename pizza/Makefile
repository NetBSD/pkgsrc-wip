# $NetBSD: Makefile,v 1.10 2012/10/05 11:20:58 asau Exp $
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

INSTALLATION_DIRS=	bin lib/java

do-build:
	printf "#! ${SH}\\nexec ${JAVA_BINPREFIX}-java -jar ${PREFIX}/lib/java/${DISTNAME}.jar \"\$$@\"\\n" > ${WRKSRC}/pizza.sh

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pizza.sh ${DESTDIR}${PREFIX}/bin/pizza
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${DESTDIR}${PREFIX}/lib/java/

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
