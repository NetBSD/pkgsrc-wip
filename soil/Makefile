# $NetBSD: Makefile,v 1.1 2013/03/10 13:58:15 othyro Exp $
#

DISTNAME=	soil
PKGNAME=	${DISTNAME}-20080707
CATEGORIES=	graphics
MASTER_SITES=	http://www.lonesock.net/files/
EXTRACT_SUFX=	.zip
EXTRACT_OPTS=	-d SOIL

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.lonesock.net/soil.html
COMMENT=	Tiny C library used primarily for uploading textures into OpenGL
LICENSE=	public-domain

WRKSRC=			${WRKDIR}/SOIL
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pax
NO_CONFIGURE=		yes
BUILD_DIRS=		projects/makefile
MAKE_FILE=		makefile
INSTALLATION_DIRS+=	include lib

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	${BUILD_DIRS}/${MAKE_FILE}
SUBST_MESSAGE.prefix=	Fixing PREFIX.
SUBST_SED.prefix=	-e "s|/usr/local|${PREFIX}|g"
SUBST_STAGE.prefix=	post-patch

post-extract:
	cd "${WRKSRC}/Simple OpenGL Image Library" && ${PAX} -rw . ..
	${RM} -rf "${WRKSRC}/Simple OpenGL Image Library"

pre-build:
	${MKDIR} ${WRKSRC}/${BUILD_DIRS}/obj

post-install:
	${CHMOD} -x ${DESTDIR}${PREFIX}/include/SOIL.h
	${CHMOD} -x ${DESTDIR}${PREFIX}/lib/libSOIL.a

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
