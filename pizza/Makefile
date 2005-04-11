# $NetBSD: Makefile,v 1.7 2005/04/11 21:14:47 tvierling Exp $
#

DISTNAME=		pizza-1.1
CATEGORIES=		wip lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=pizzacompiler/}
EXTRACT_SUFX=		.jar

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://pizzacompiler.sourceforge.net/
COMMENT=		Pizza language is an extension to Java

WRKSRC=			${WRKDIR}

do-extract:

do-build:

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}.jar \
		${PREFIX}/bin/pizza.jar
	${ECHO} "#!/bin/sh" > ${PREFIX}/bin/pizza
	${ECHO} "if [ \"\" = \"\`echo \$$CLASSPATH|grep pizza.jar\`\" ];then" >> ${PREFIX}/bin/pizza
	${ECHO} "echo \"WARNING: You must add ${PREFIX}/bin/pizza.jar to CLASSPATH\"" >> ${PREFIX}/bin/pizza
	${ECHO} "fi" >> ${PREFIX}/bin/pizza
	${ECHO} "CLASSPATH=${PREFIX}/bin/pizza.jar:${CLASSPATH}" >> ${PREFIX}/bin/pizza
	${ECHO} "java -jar ${PREFIX}/bin/pizza.jar \$$*" >> ${PREFIX}/bin/pizza
	${CHMOD} +x ${PREFIX}/bin/pizza

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
