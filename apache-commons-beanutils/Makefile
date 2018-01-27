# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:37 asau Exp $
#

DISTNAME=	commons-beanutils-1.8.3-bin
PKGNAME=	apache-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://archive.apache.org/dist/commons/beanutils/binaries/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://commons.apache.org/beanutils/
COMMENT=	Utility for manipulating JavaBeans
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/commons-beanutils-1.8.3

NO_BUILD=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=		yes
PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15 sun-jdk14

INSTALLATION_DIRS=	lib/java share/doc/apache-commons-beanutils

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-beanutils-1.8.3.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-beanutils.jar
	${INSTALL_DATA} ${WRKSRC}/commons-beanutils-bean-collections-1.8.3.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-beanutils-bean-collections.jar
	${INSTALL_DATA} ${WRKSRC}/commons-beanutils-core-1.8.3.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-beanutils-core.jar
	cd ${WRKSRC}/apidocs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/apache-commons-beanutils

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
