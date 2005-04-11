# $NetBSD: Makefile,v 1.8 2005/04/11 21:13:14 tvierling Exp $

DISTNAME=	jakarta-log4j-1.2.8
CATEGORIES=	www
MASTER_SITES?=	http://jakarta.apache.org/log4j/

MAINTAINER=	drue@users.sourceforge.net
HOMEPAGE=	http://jakarta.apache.org/log4j/docs/index.html
COMMENT=	Logging facility for Java

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_JAVA=	run

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/dist/lib/log4j-1.2.8.jar ${PREFIX}/lib/java/log4j.jar
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/java/jakarta-log4j
	cd ${WRKSRC}/docs && ${PAX} -rwpe . ${PREFIX}/share/doc/java/jakarta-log4j
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${PREFIX}/share/doc/java/jakarta-log4j/COPYRIGHT
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/java/jakarta-log4j
	cd ${WRKSRC}/examples && ${PAX} -rwpe . ${PREFIX}/share/examples/java/jakarta-log4j

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
