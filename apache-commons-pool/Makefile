# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:38 asau Exp $
#

DISTNAME=	commons-pool-1.5.5-bin
PKGNAME=	apache-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://archive.apache.org/dist/commons/pool/binaries/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://commons.apache.org/pool/
COMMENT=	Pooling implementation for Java objects
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/commons-pool-1.5.5

NO_BUILD=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=	run

INSTALLATION_DIRS=	lib/java share/doc/apache-commons-pool

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-pool-1.5.5.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-pool.jar
	cd ${WRKSRC}/apidocs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/apache-commons-pool


.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
