# $NetBSD$

CSOUND_VERSION=		6.13.0
DISTNAME=		${CSOUND_VERSION}
PKGNAME=		csound6-${CSOUND_VERSION}
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GITHUB:=csound/}
GITHUB_PROJECT=		csound
GITHUB_TAG=		${PKGVERSION_NOREV}
DIST_SUBDIR=		${PKGNAME_NOREV}
EXTRACT_USING=		bsdtar

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://csound.com/
COMMENT=		Software synthesizer and sequencer
LICENSE=		gnu-lgpl-v2.1  # or later

.include "../../mk/bsd.prefs.mk"

# There are multiple code paths for different versions (try to omit old ones)
USE_LANGUAGES=		c99 c++11
USE_TOOLS+=		flex bison
CFLAGS+=		-g -D__PKGSRC_PREFIX__=\"${PREFIX}/\" -DBETA
USE_CMAKE=		yes
CMAKE_ARGS+=		-DUSE_PULSEAUDIO:BOOL=ON
CMAKE_ARGS+=		-DBUILD_RELEASE=1 -DCMAKE_BUILD_TYPE=Release

# -----------------------------------------------------------------------------
# This section contains more or less ugly workarounds for build problems
# If somebody can fix these problems correctly, please do!

# CMAKE_INSTALL_RPATH doesn't work for some reason, so do it here
LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/csound6
# Workaround for missing image libraries (cmake don't link them otherwise)
LDFLAGS+=		-ljpeg -lpng
# Link Backtrace Information Library on NetBSD (to fix unresolved symbols)
.if ${OPSYS} == "NetBSD"
LDFLAGS+=		-lexecinfo
.endif
# Backtrace Information Library was introduced with NetBSD 7
NOT_FOR_PLATFORM=	NetBSD-[0-6].*-*

# In theory 3.x should be supported, but there are undefined symbols with 3.7
PYTHON_VERSIONS_ACCEPTED=	27

# Some scripts use non-POSIX syntax and /bin/sh as interpreter
CHECK_PORTABILITY_SKIP+=	installer/misc/makedeb.sh \
				installer/macosx/beta-build.sh \
				installer/macosx/release-build-10.8.sh \
				installer/macosx/release-build-10.10.sh \
				installer/macosx/release-build.sh \
				frontends/max_csound_tilde/installer/build-installer.sh \
				frontends/max_csound_tilde/installer/build-installer-windows.sh
# -----------------------------------------------------------------------------

WRKSRC=			${WRKDIR}/csound-${CSOUND_VERSION}
INSTALLATION_DIRS=	bin

post-install:
	cd ${DESTDIR}${PREFIX} && ${LN} -s ../lib/csound6/csound bin/csound6

.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
# FLTK version 1.4 is supported too
#.include "../../x11/fltk13/buildlink3.mk"
.include "../../wip/fltk14-devel/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
