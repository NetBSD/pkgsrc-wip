# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:37 asau Exp $
#

DISTNAME=	commons-digester-2.0-bin
PKGNAME=	apache-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://mirrors.axint.net/apache//commons/digester/binaries/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://commons.apache.org/digester/
COMMENT=	Rule based XML Java object mapping tool
LICENSE=	apache-2.0

DEPENDS+=	apache-commons-beanutils>=1.8.3:../../wip/apache-commons-beanutils
DEPENDS+=	apache-commons-logging>=-1.1.1:../../wip/apache-commons-logging

WRKSRC=		${WRKDIR}/commons-digester-2.0

NO_BUILD=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=		yes
PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15

INSTALLATION_DIRS=	lib/java share/doc/apache-commons-digester

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-digester-2.0.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-digester.jar
	cd ${WRKSRC}/apidocs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/apache-commons-digester


.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
