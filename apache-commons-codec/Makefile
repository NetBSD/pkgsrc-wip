# $NetBSD: Makefile,v 1.4 2012/12/03 13:35:39 othyro Exp $
#

DISTNAME=	commons-codec-1.7-bin
PKGNAME=	apache-${DISTNAME:S/-bin//}
CATEGORIES=	devel java
MASTER_SITES=	http://archive.apache.org/dist/commons/codec/binaries/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://commons.apache.org/codec/
COMMENT=	Encoder and decoders such as Base64 and hexadecimal codec
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/commons-codec-${PKGVERSION_NOREV}

NO_BUILD=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=		yes
PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15

INSTALLATION_DIRS=	lib/java share/doc/apache-commons-codec

do-install:
	${INSTALL_DATA} ${WRKSRC}/commons-codec-${PKGVERSION_NOREV}.jar \
		${DESTDIR}${PREFIX}/lib/java/commons-codec.jar
	cd ${WRKSRC}/apidocs && pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/apache-commons-codec


.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
