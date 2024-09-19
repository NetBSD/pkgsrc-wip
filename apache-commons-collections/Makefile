# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:37 asau Exp $
#

DISTNAME=	commons-collections-3.2.1-bin
PKGNAME=	apache-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://archive.apache.org/dist/commons/collections/binaries/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://commons.apache.org/collections/
COMMENT=	Set of abstract data type interfaces and implementations
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/commons-collections-3.2.1

NO_BUILD=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=	run

INSTALLATION_DIRS=	lib/java share/doc/apache-commons-collections

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-collections-3.2.1.jar\
		${DESTDIR}${PREFIX}/lib/java/commons-collections.jar
	${INSTALL_DATA} ${WRKSRC}/commons-collections-testframework-3.2.1.jar\
		${DESTDIR}${PREFIX}/lib/java/commons-collections-testframework.jar
	cd ${WRKSRC}/apidocs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/apache-commons-collections


.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
