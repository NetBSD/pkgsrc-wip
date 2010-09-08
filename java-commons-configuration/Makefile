# $NetBSD: Makefile,v 1.1.1.1 2010/09/08 21:53:45 jihbed Exp $
#

DISTNAME=	commons-configuration-1.6
PKGNAME=	java-${DISTNAME}
CATEGORIES=	devel java
MASTER_SITES=	http://www.bizdirusa.com/mirrors/apache//commons/configuration/binaries/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://commons.apache.org/configuration/
COMMENT=	Java based library providing a generic configuration interface
LICENSE=	apache-2.0

DEPENDS+=	java-commons-beanutils>=1.8.3:../../wip/java-commons-beanutils
DEPENDS+=	java-commons-codec>=1.4:../../wip/java-commons-codec
DEPENDS+=	java-commons-collections>=3.2.1:../../wip/java-commons-collections
DEPENDS+=	java-commons-digester>=2.0:../../wip/java-commons-digester
DEPENDS+=	java-commons-lang>=2.5:../../wip/java-commons-lang
DEPENDS+=	java-commons-logging>=1.1.1:../../wip/java-commons-logging

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=	yes
PKG_JVMS_ACCEPTED= sun-jdk6 sun-jdk15 sun-jdk14

INSTALLATION_DIRS=	lib/java share/doc/java-commons-configuration

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-configuration-1.6.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-configuration.jar
	cd ${WRKSRC}/docs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/java-commons-configuration

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
