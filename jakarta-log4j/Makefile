# $NetBSD: Makefile,v 1.12 2012/10/01 21:43:22 asau Exp $
#

DISTNAME=	logging-log4j-1.3alpha-8
PKGNAME=	jakarta-log4j-1.3a-8
CATEGORIES=	www
MASTER_SITES=	http://archive.apache.org/dist/logging/log4j/1.3alpha-8/

MAINTAINER=	drue@users.sourceforge.net
HOMEPAGE=	http://logging.apache.org/log4j/docs/
COMMENT=	Logging facility for Java
#LICENSE=	# TODO: (see mk/license.mk)

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_JAVA=	run
USE_TOOLS+=	pax

USE_LANGUAGES=	c++

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/lib/log4j-all-1.3alpha-8.jar ${DESTDIR}${PREFIX}/lib/java/log4j.jar
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/java/jakarta-log4j
	cd ${WRKSRC}/docs && pax -rwpe . ${DESTDIR}${PREFIX}/share/doc/java/jakarta-log4j
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${DESTDIR}${PREFIX}/share/doc/java/jakarta-log4j/COPYRIGHT
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/java/jakarta-log4j
	cd ${WRKSRC}/examples && pax -rwpe . ${DESTDIR}${PREFIX}/share/examples/java/jakarta-log4j

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
