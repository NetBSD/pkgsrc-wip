# $NetBSD: Makefile,v 1.3 2012/10/01 21:43:22 asau Exp $
#

DISTNAME=	tritonus_share-0.3.6
PKGNAME=	java-tritonus-share-0.3.6
CATEGORIES=	audio java
MASTER_SITES=	http://tritonus.org/
EXTRACT_SUFX=	.jar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tritonus.org/plugins.html
COMMENT=	Shared classes required by all other Tritonus plug-ins
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}

NO_BUILD=	yes
USE_LANGUAGES=	# none

USE_JAVA=		yes
PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15 sun-jdk14

ONLY_FOR_PLATFORM=	NetBSD-*-i386  Linux-*-i386 Darwin-*-i386

INSTALLATION_DIRS=	lib/java

do-install:
	${INSTALL_DATA} ${WRKSRC}/tritonus_share-0.3.6.jar \
			${DESTDIR}${PREFIX}/lib/java/tritonus-share.jar

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
