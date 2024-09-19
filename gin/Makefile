# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:35 asau Exp $
#

DISTNAME=	gin-1.5
CATEGORIES=	devel
MASTER_SITES=	http://google-gin.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://code.google.com/p/google-gin/
COMMENT=	GIN is Guice for Google Web Toolkit client-side code
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}

NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_JAVA=	run
USE_JAVA2=	yes

USE_TOOLS+=	pax

GINDOCDIR=	share/doc/gin
GINDIR=		lib/java/gin

INSTALLATION_DIRS=	bin ${GINDOCDIR} ${GINDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*jar ${DESTDIR}${PREFIX}/${GINDIR}
	cd ${WRKSRC} && pax -rw -pmp \
		LICENSE README javadoc \
		${DESTDIR}${PREFIX}/${GINDOCDIR}

.include "../../mk/bsd.pkg.mk"
