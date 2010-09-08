# $NetBSD: Makefile,v 1.1.1.1 2010/09/08 21:03:38 jihbed Exp $
#

DISTNAME=	commons-digester-2.0-bin
PKGNAME=	java-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://mirrors.axint.net/apache//commons/digester/binaries/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://commons.apache.org/digester/
COMMENT=	Rule based XML Java object mapping tool
LICENSE=	apache-2.0

DEPENDS+=	java-commons-beanutils>=1.8.3:../../wip/java-commons-beanutils
DEPENDS+=	java-commons-logging>=-1.1.1:../../wip/java-commons-logging

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/commons-digester-2.0

NO_BUILD=		yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=	yes
PKG_JVMS_ACCEPTED= sun-jdk6 sun-jdk15

INSTALLATION_DIRS=	lib/java share/doc/java-commons-digester

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-digester-2.0.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-digester.jar
	cd ${WRKSRC}/apidocs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/java-commons-digester


.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
