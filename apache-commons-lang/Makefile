# $NetBSD: Makefile,v 1.1.1.1 2010/09/08 23:46:13 jihbed Exp $
#

DISTNAME=	commons-lang-2.5-bin
PKGNAME=	apache-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://apache.inetbridge.net//commons/lang/binaries/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://commons.apache.org/lang/
COMMENT=	Extension of the java.lang package
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/commons-lang-2.5

NO_BUILD=	yes
USE_LANGUAGES=	# none

USE_JAVA=	yes
PKG_JVMS_ACCEPTED= sun-jdk6 sun-jdk15 sun-jdk14

INSTALLATION_DIRS=	lib/java

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-lang-2.5.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-lang.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
