# $NetBSD: Makefile,v 1.2 2012/09/22 15:50:00 othyro Exp $
#

DISTNAME=	pcsx2-1.0.0-r5350-sources.7z
PKGNAME=	${DISTNAME:S/-r5350-sources.7z//}
CATEGORIES=	emulators
MASTER_SITES=	http://pcsx2.net/
EXTRACT_SUFX=
EXTRACT_CMD=	7z x $$extract_file

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pcsx2.net/
COMMENT=	Playstation 2 Emulator
#LICENSE=	gnu-gpl-v3 AND modified-bsd AND expatobjc-license AND gnu-gpl-v2 AND gnu-lgpl-v2.1 AND gnu-lgpl-v3 AND public-domain

BUILD_DEPENDS+=	p7zip-[0-9]*:../../archivers/p7zip

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/pcsx2-1.0.0-r5350-sources
USE_LANGUAGES=	c c++
USE_TOOLS+=	msgmerge
USE_CMAKE=	yes
CMAKE_ARGS+=	-DPACKAGE_MODE=1
CMAKE_ARGS+=	-DCG_GL_LIBRARY=${BUILDLINK_PREFIX.Cg-compiler}/emul/linux32/lib/libCgGL.so
CMAKE_ARGS+=	-DCG_LIBRARY=${BUILDLINK_PREFIX.Cg-compiler}/emul/linux32/lib/libCg.so
CMAKE_ARGS+=	-DOPENGL_xmesa_INCLUDE_DIR=${BUILDLINK_PREFIX.MesaLib}/include/GL
CMAKE_ARGS+=	-Dlibdl=${DL_LIBS}
CMAKE_ARGS+=	-DX11_ICE_INCLUDE_PATH=${BUILDLINK_PREFIX.libICE}/include/X11/ICE

.include "../../devel/sparsehash/buildlink3.mk"
.include "../../wip/libSoundTouch/buildlink3.mk"
.include "../../audio/portaudio/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../wip/Cg-compiler/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../devel/subversion-base/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../archivers/bzip2/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
