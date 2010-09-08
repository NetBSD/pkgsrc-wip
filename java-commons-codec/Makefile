# $NetBSD: Makefile,v 1.1.1.1 2010/09/08 21:41:34 jihbed Exp $
#

DISTNAME=	commons-codec-1.4-bin
PKGNAME=	java-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://apache.multihomed.net//commons/codec/binaries/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://commons.apache.org/codec/
COMMENT=	Encoder and decoders such as Base64 and hexadecimal codec
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/commons-codec-1.4

NO_BUILD=		yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=	yes
PKG_JVMS_ACCEPTED= sun-jdk6 sun-jdk15 sun-jdk14

INSTALLATION_DIRS=	lib/java share/doc/java-commons-codec

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-codec-1.4.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-codec.jar
	cd ${WRKSRC}/apidocs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/java-commons-codec


.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
