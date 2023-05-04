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

USE_TOOLS+=	gmake perl bash pkg-config pax tar cmake

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=		0ad-data-${PKGVERSION}:../../wip/0ad-data
BUILD_DEPENDS+=		premake5-[0-9]*:../../devel/premake5
BUILD_DEPENDS+=		zip-[0-9]*:../../archivers/zip
TOOL_DEPENDS+=		python${PYTHON_VERSION_DEFAULT}-[0-9]*:../../lang/python${PYTHON_VERSION_DEFAULT}

SUBST_CLASSES+=			sysincludedir
SUBST_MESSAGE.sysincludedir=	Fixing "/usr/local" path assumption
SUBST_STAGE.sysincludedir=	pre-configure
SUBST_FILES.sysincludedir=	build/premake/extern_libs5.lua
SUBST_FILES.sysincludedir+=	build/premake/premake5.lua
SUBST_SED.sysincludedir+=	-e "s,/usr/local/,${PREFIX}/,g"

# thanks to Guix:
# 0ad only builds fine with a specific version of mozjs
# (version 78.6 for 0ad-0.0.25).
# Here we change the error in case of version mismatch to a warning,
# and add some minor compatibility fixes.
SUBST_CLASSES+=		mozjs
SUBST_MESSAGE.mozjs=	Fixing mozjs version error
SUBST_STAGE.mozjs=	pre-configure
SUBST_FILES.mozjs=	source/scriptinterface/ScriptTypes.h
SUBST_SED.mozjs+=	-e "s,\#error Your compiler is trying to use,\#warning Your compiler is trying to use,g"

SUBST_CLASSES+=		mozjs2
SUBST_MESSAGE.mozjs2=	Fixing mozjs version error
SUBST_STAGE.mozjs2=	pre-configure
SUBST_FILES.mozjs2+=	source/scriptinterface/ScriptContext.cpp
SUBST_SED.mozjs2+=	-e "s|JS::PrepareZoneForGC(|JS::PrepareZoneForGC(m_cx, |g"

DATADIR=	${PREFIX}/share/${PKGBASE}

INSTALLATION_DIRS+=	lib/${PKGBASE}
INSTALLATION_DIRS+=	${DATADIR}
INSTALLATION_DIRS+=	${DATADIR}/mods/public
INSTALLATION_DIRS+=	${DATADIR}/mods/mod

.include "options.mk"

do-configure:
	${RUN} cd ${WRKSRC}/build/workspaces && ./clean-workspaces.sh
	${RUN} cd ${WRKSRC}/build/workspaces && ./update-workspaces.sh \
		--bindir=${PREFIX}/bin \
		--datadir=${DATADIR} \
		--libdir=${PREFIX}/lib/${PKGBASE} \
		--with-system-premake5 \
		--with-system-mozjs \
		--without-pch \
		--disable-atlas \
		${CONFIGURE_TESTS}

# TODO: needs "wx"
# nvtt, notes from gentoo:
# Build bundled NVTT
# nvtt is abandoned upstream and 0ad has forked it and added fixes.
# Use their copy. bug #768930
# --with-system-nvtt \
# options:
# tests:
# --without-tests
#  editor:
# --disable-atlas

do-build:
	${RUN} cd ${WRKSRC} && \
		${GMAKE} config=release verbose=1 -j ${_MAKE_JOBS_N} \
		-C build/workspaces/gcc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/binaries/system/pyrogenesis ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/build/resources/0ad.sh ${DESTDIR}${PREFIX}/bin/0ad
	# atlas:
	# ${INSTALL_PROGRAM} ${WRKSRC}/binaries/system/ActorEditor ${DESTDIR}${PREFIX}/bin
	# missing:
	# libnvcore.a libnvimage.so libnvmath.so libnvtt.so
	# TODO: all of these should be .so.
	cd ${WRKSRC}/binaries/system && ${INSTALL_LIB} libatlas.a libAtlasUI.a \
		libengine.a libgladwrapper.a libglooxwrapper.a libgraphics.a \
		libgui.a liblobby.a liblowlevel.a libmocks_real.a libmocks_test.a \
		libmongoose.a libnetwork.a librlinterface.a libscriptinterface.a \
		libsimulation2.a libtinygettext.a libCollada.so \
		${DESTDIR}${PREFIX}/lib/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/build/resources/0ad.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/build/resources/0ad.png ${DESTDIR}${PREFIX}/share/pixmaps
	# if atlas?: + tools
.for d in config l10n tests
	cd ${WRKSRC}/binaries/data && ${PAX} -rw ${d} ${DESTDIR}${DATADIR}
.endfor
	${TAR} xf ${WRKSRC}/binaries/data/mods/public/public.zip -C ${DESTDIR}${DATADIR}/mods/public --no-same-permissions
	${TAR} xf ${WRKSRC}/binaries/data/mods/mod/mod.zip -C ${DESTDIR}${DATADIR}/mods/mod --no-same-permissions


.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../chat/gloox/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
#.include "../../graphics/nvidia-texture-tools/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../lang/mozjs78/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../textproc/fmtlib/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
