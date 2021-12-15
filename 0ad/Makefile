# $NetBSD$

.include "Makefile.common"

DISTNAME=	${DISTVERSION}-build
PKGNAME=	${DISTNAME:S/-unix-build//:S/-alpha/.alpha/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Historical real-time strategy game
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/${DISTNAME:S/-unix-build//}
# Requires C++17 and add "--std" option itself
GCC_REQD+=	7
USE_LANGUAGES=	c c++

USE_TOOLS+=	gmake perl bash pkg-config

DEPENDS+=	0ad-data-${PKGVERSION}:../../wip/0ad-data
DEPENDS+=	premake5-[0-9]*:../../wip/premake5

do-configure:
	${RUN} cd ${WRKSRC}/build/workspaces && ./clean-workspaces.sh
	${RUN} cd ${WRKSRC}/build/workspaces && ./update-workspaces.sh \
		--bindir=${PREFIX}/bin \
		--datadir=${PREFIX}/share/${PKGBASE} \
		--libdir=${PREFIX}/lib/${PKGBASE} \
		--with-system-premake5 \
		--with-system-mozjs \
		--with-system-nvtt \
		--without-pch \
		--disable-atlas

do-build:
	${RUN} cd ${WRKSRC} && \
		${GMAKE} config=release verbose=1 -j ${_MAKE_JOBS_N} \
		-C build/workspaces/gcc

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../chat/gloox/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/nvidia-texture-tools/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/mozjs78/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
