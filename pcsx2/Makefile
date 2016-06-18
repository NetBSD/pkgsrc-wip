# $NetBSD: Makefile,v 1.9 2015/04/19 15:10:39 othyro Exp $
#

GITHUB_PROJECT=	pcsx2
DISTNAME=	v1.0
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=PCSX2/}
DIST_SUBDIR=	${GITHUB_PROJECT}

# The DISTFILE to download is an HTTP-only attachment.
# The getsite.sh script uses cURL download the attached file.

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pcsx2.net/
COMMENT=	Playstation 2 Emulator
LICENSE=	gnu-gpl-v3 AND modified-bsd AND mit AND gnu-gpl-v2 AND gnu-lgpl-v2.1 AND gnu-lgpl-v3 AND public-domain AND sgi-free-software-b-v2.0

EXTRACT_USING=	gtar
WRKSRC=		${WRKDIR}/pcsx2-1.0
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake msgmerge
USE_CMAKE=	yes
CMAKE_ARGS+=	-DPACKAGE_MODE=1
CMAKE_ARGS+=	-DCG_GL_LIBRARY=${BUILDLINK_PREFIX.Cg-compiler}/emul/linux32/lib/libCgGL.so
CMAKE_ARGS+=	-DCG_LIBRARY=${BUILDLINK_PREFIX.Cg-compiler}/emul/linux32/lib/libCg.so
CMAKE_ARGS+=	-DOPENGL_xmesa_INCLUDE_DIR=${BUILDLINK_PREFIX.MesaLib}/include/GL
CMAKE_ARGS+=	-DX11_ICE_INCLUDE_PATH=${BUILDLINK_PREFIX.libICE}/include/X11/ICE

.include "../../mk/bsd.prefs.mk"

.if $(OPSYS) != "Linux"
BUILDLINK_TRANSFORM=	rm:-ldl
CMAKE_ARGS+=		-Dlibdl=NO
.else
CMAKE_ARGS+=		-Dlibdl=${DL_LIBS}
.endif


BUILDLINK_DEPMETHOD.gtk2=	build
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/sparsehash/buildlink3.mk"
.include "../../audio/soundtouch/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../lang/Cg-compiler/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
BUILDLINK_DEPMETHOD.bzip2=	build
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
