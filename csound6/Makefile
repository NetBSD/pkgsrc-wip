# $NetBSD: Makefile,v 1.79 2023/08/14 05:23:46 wiz Exp $

DISTNAME=	csound-6.18.1
PKGNAME=	${DISTNAME:S/csound/csound6/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=csound/}
GITHUB_PROJECT=	csound

MAINTAINER=	mrg@eterna.com.au
HOMEPAGE=	https://github.com/csound/csound
COMMENT=	Software synthesizer and sequencer
LICENSE=	gnu-lgpl-v2.1 # or later

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison flex

CMAKE_CONFIGURE_ARGS+=	-DBUILD_HDF5_OPCODES=OFF
# CMAKE_INSTALL_RPATH doesn't work for some reason, so do it here.
LDFLAGS+=	${COMPILER_RPATH_FLAG}${PREFIX}/lib/csound6

INSTALLATION_DIRS=	bin

CHECK_PORTABILITY_SKIP+= \
	Android/build-all.sh \
	installer/misc/makedeb.sh \
	installer/macosx/beta-build.sh \
	installer/macosx/release-build.sh \
	installer/macosx/release-build-10.8.sh \
	installer/macosx/release-build-10.10.sh \
	frontends/max_csound_tilde/installer/build-installer.sh \
	frontends/max_csound_tilde/installer/build-installer-windows.sh

.include "../../mk/bsd.prefs.mk"

post-install:
	cd ${DESTDIR}${PREFIX} && \
	${LN} -f -s csound bin/csound6

.include "options.mk"

.include "../../audio/portmidi/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/liblo/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
