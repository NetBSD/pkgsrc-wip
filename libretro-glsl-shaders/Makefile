# $NetBSD$

PKGNAME=	libretro-glsl-shaders-1.7.3
DISTNAME=	retroarch-assets-${PKGVERSION_NOREV}
PKGREVISION=	2
CATEGORIES=	emulators
MASTER_SITES=	-http://buildbot.libretro.com/stable/${PKGVERSION_NOREV}/windows-msvc2010/x86_64/RetroArch.7z
EXTRACT_SUFX=	.7z

MAINTAINER=	nia.alarie@gmail.com
COMMENT=	Libretro GLSL shaders

USE_LANGUAGES=	# none
USE_TOOLS+=	find
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/shaders/shaders_glsl

do-install:
	cd ${WRKSRC} && ${FIND} * -type d -exec ${INSTALL_DATA_DIR} \
	    ${DESTDIR}${PREFIX}/share/libretro/shaders/{} \;
	cd ${WRKSRC} && ${FIND} * -type f -exec ${INSTALL_DATA} {} \
	    ${DESTDIR}${PREFIX}/share/libretro/shaders/{} \;

.include "../../mk/bsd.pkg.mk"
