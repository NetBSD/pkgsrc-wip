# $NetBSD: Makefile,v 1.3 2012/09/24 16:56:38 asau Exp $
#

DISTNAME=	commons-lang-2.5-bin
PKGNAME=	apache-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://archive.apache.org/dist/commons/lang/binaries/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://commons.apache.org/lang/
COMMENT=	Extension of the java.lang package
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/commons-lang-2.5

NO_BUILD=	yes
USE_LANGUAGES=	# none

USE_JAVA=		yes
PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15 sun-jdk14

INSTALLATION_DIRS=	lib/java

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-lang-2.5.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-lang.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
