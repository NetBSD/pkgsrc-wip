# $NetBSD: Makefile,v 1.3 2004/03/21 12:16:22 poppnk Exp $
#

DISTNAME=		pizza-1.1
CATEGORIES=		wip lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pizzacompiler/}
EXTRACT_SUFX=		.jar

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://pizzacompiler.sourceforge.net/
COMMENT=		Pizza language is an extension to Java

WRKSRC=			${WRKDIR}/
USE_BUILDLINK2=		yes

do-extract:

do-build:

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar \
		${PREFIX}/bin/pizza.jar
	${ECHO} "#!/bin/sh" > ${PREFIX}/bin/pizza
	${ECHO} "CLASSPATH=${PREFIX}/bin/pizza.jar:${CLASSPATH}" >> ${PREFIX}/bin/pizza
	${ECHO} "java -jar ${PREFIX}/bin/pizza.jar \$$*" >> ${PREFIX}/bin/pizza
	${CHMOD} +x ${PREFIX}/bin/pizza

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
