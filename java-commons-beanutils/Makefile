# $NetBSD: Makefile,v 1.1.1.1 2010/09/08 20:37:58 jihbed Exp $
#

DISTNAME=	commons-beanutils-1.8.3-bin
PKGNAME=	java-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://mirrors.axint.net/apache//commons/beanutils/binaries/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://commons.apache.org/beanutils/
COMMENT=	Utility for manipulating JavaBeans
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/commons-beanutils-1.8.3

NO_BUILD=		yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=	yes
PKG_JVMS_ACCEPTED= sun-jdk6 sun-jdk15 sun-jdk14

INSTALLATION_DIRS=	lib/java share/doc/java-commons-beanutils

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-beanutils-1.8.3.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-beanutils.jar
	${INSTALL_DATA} ${WRKSRC}/commons-beanutils-bean-collections-1.8.3.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-beanutils-bean-collections.jar
	${INSTALL_DATA} ${WRKSRC}/commons-beanutils-core-1.8.3.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-beanutils-core.jar
	cd ${WRKSRC}/apidocs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/java-commons-beanutils

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
