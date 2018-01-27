# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:37 asau Exp $
#

DISTNAME=	commons-configuration-1.6
PKGNAME=	apache-${DISTNAME}
CATEGORIES=	devel java
MASTER_SITES=	http://www.bizdirusa.com/mirrors/apache//commons/configuration/binaries/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://commons.apache.org/configuration/
COMMENT=	Java based library providing a generic configuration interface
LICENSE=	apache-2.0

DEPENDS+=	apache-commons-beanutils>=1.8.3:../../wip/apache-commons-beanutils
DEPENDS+=	apache-commons-codec>=1.4:../../wip/apache-commons-codec
DEPENDS+=	apache-commons-collections>=3.2.1:../../wip/apache-commons-collections
DEPENDS+=	apache-commons-digester>=2.0:../../wip/apache-commons-digester
DEPENDS+=	apache-commons-lang>=2.5:../../wip/apache-commons-lang
DEPENDS+=	apache-commons-logging>=1.1.1:../../wip/apache-commons-logging

NO_BUILD=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=		yes
PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15 sun-jdk14

INSTALLATION_DIRS=	lib/java share/doc/apache-commons-configuration

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-configuration-1.6.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-configuration.jar
	cd ${WRKSRC}/docs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/apache-commons-configuration

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
