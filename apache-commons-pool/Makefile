# $NetBSD: Makefile,v 1.2 2012/01/01 15:35:43 jihbed Exp $
#

DISTNAME=	commons-pool-1.5.5-bin
PKGNAME=	apache-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	${MASTER_SITE_APACHE:=/commons/pool/binaries/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://commons.apache.org/pool/
COMMENT=	Pooling implementation for Java objects
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

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
