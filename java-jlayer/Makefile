# $NetBSD: Makefile,v 1.4 2012/11/12 16:26:42 othyro Exp $
#

DISTNAME=	jlayer1.0.1
PKGNAME=	java-jlayer-1.0.1
CATEGORIES=	audio java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=javalayer/}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.javazoom.net/javalayer/javalayer.html
COMMENT=	Library to decode, convert and play MP3 files
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/JLayer1.0.1

NO_BUILD=	yes
USE_TOOLS+=	pax
USE_LANGUAGES=	# none

USE_JAVA=		yes
PKG_JVMS_ACCEPTED=	sun-jdk6 sun-jdk15 sun-jdk14

INSTALLATION_DIRS=	lib/java share/doc/java-jlayer

do-install:
	${INSTALL_DATA} ${WRKSRC}/jl1.0.1.jar\
		${DESTDIR}${PREFIX}/lib/java/jlayer.jar
	cd ${WRKSRC}/doc&& pax -rw -pp . ${DESTDIR}${PREFIX}/share/doc/java-jlayer

.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
