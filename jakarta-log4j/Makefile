# $NetBSD: Makefile,v 1.3 2003/06/30 10:56:07 drue Exp $

DISTNAME=	jakarta-log4j-1.2.8
#WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=		devel
MASTER_SITES?=		http://jakarta.apache.org/log4j/

MAINTAINER=	drue@users.sourceforge.net
HOMEPAGE=	http://jakarta.apache.org/log4j/docs/index.html
COMMENT=	Logging facility for Java

USE_BUILDLINK2= yes
NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_JAVA=	run

DOCDIR=	share/doc/java/jakarta-log4j
EGDIR=	share/examples/java/jakarta-log4j

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/java
	${INSTALL_DATA} ${WRKSRC}/dist/lib/log4j-1.2.8.jar ${PREFIX}/lib/java/log4j.jar
	${INSTALL_DATA_DIR} ${PREFIX}/${DOCDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/${EGDIR}
	${CHMOD} -R ugo-w ${WRKSRC}/examples
	cd ${WRKSRC}/examples && ${PAX} -rw . ${PREFIX}/${EGDIR}
	${CHMOD} -R ugo-w ${WRKSRC}/docs
	cd ${WRKSRC}/docs && ${PAX} -rw . ${PREFIX}/${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE.txt ${PREFIX}/${DOCDIR}/COPYRIGHT

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
