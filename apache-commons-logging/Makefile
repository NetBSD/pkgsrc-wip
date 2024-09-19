# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:38 asau Exp $
#

DISTNAME=	commons-logging-1.1.1-bin
PKGNAME=	apache-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://archive.apache.org/dist/commons/logging/binaries/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://commons.apache.org/logging/
COMMENT=	Commmon wrapper interface for several logging APIs
LICENSE=	apache-2.0

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
