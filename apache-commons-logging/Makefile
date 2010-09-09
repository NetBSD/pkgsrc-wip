# $NetBSD: Makefile,v 1.1.1.1 2010/09/09 00:13:40 jihbed Exp $
#

DISTNAME=	commons-logging-1.1.1-bin
PKGNAME=	apache-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://www.fightrice.com/mirrors/apache//commons/logging/binaries/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://commons.apache.org/logging/
COMMENT=	Commmon wrapper interface for several logging APIs
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/commons-logging-1.1.1

NO_BUILD=	yes
USE_LANGUAGES=	# none

USE_JAVA=	run

INSTALLATION_DIRS=	lib/java

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-logging-1.1.1.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-logging.jar
	${INSTALL_DATA} ${WRKSRC}/commons-logging-adapters-1.1.1.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-logging-adapters.jar
	${INSTALL_DATA} ${WRKSRC}/commons-logging-api-1.1.1.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-logging-api.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
