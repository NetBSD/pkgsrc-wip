# $NetBSD: Makefile,v 1.14 2012/09/24 18:26:53 asau Exp $

DISTNAME=	chromium-54.0.2823.2
PKGNAME=	${DISTNAME:S/chromium-/chromium-browser-/}
DIST_SUBDIR=	${PKGBASE}
CATEGORIES=	www
MASTER_SITES=	https://gsdview.appspot.com/chromium-browser-official/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dev.chromium.org/Home
COMMENT=	Open-source browser project
LICENSE=	modified-bsd

USE_TOOLS+=	bash bison flex gmake pax perl pkg-config
USE_LANGUAGES=	c c++

BUILD_DEPENDS+=	gperf-[0-9]*:../../devel/gperf
BUILD_DEPENDS+=	yasm-[0-9]*:../../devel/yasm

ONLY_FOR_PLATFORM=	*-*-arm *-*-i386 *-*-x86_64

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux" || ${OPSYS} == "DragonFly" || ${OPSYS} == "FreeBSD" || ${OPSYS} == "NetBSD"
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

REPLACE_PYTHON+=	*.py
REPLACE_PYTHON+=	*/*.py
REPLACE_PYTHON+=	*/*/*.py
REPLACE_PYTHON+=	*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*/*/*/*/*.py
REPLACE_PYTHON+=	*/*/*/*/*/*/*/*/*/*/*.py

SUBST_CLASSES+=		python
SUBST_MESSAGE.python=	Fixing PYTHON path.
SUBST_SED.python=	-e "s|/usr/bin/python|${PYTHONBIN}|1"
SUBST_FILES.python+=	testing/chromoting/browser_test_commands_linux.txt
SUBST_FILES.python+=	testing/gtest/xcode/gtest.xcodeproj/project.pbxproj
SUBST_FILES.python+=	third_party/WebKit/LayoutTests/media/track/opera/track/webvtt/rendering/reftest/build-manifest.py
SUBST_FILES.python+=	third_party/WebKit/Tools/Scripts/generate-w3c-directory-owner-json
SUBST_FILES.python+=	third_party/WebKit/Tools/Scripts/print-json-test-results
SUBST_FILES.python+=	third_party/WebKit/Tools/Scripts/print-layout-test-times
SUBST_FILES.python+=	third_party/WebKit/Tools/Scripts/print-layout-test-types
SUBST_FILES.python+=	third_party/WebKit/Tools/Scripts/print-stale-test-expectations-entries
SUBST_FILES.python+=	third_party/WebKit/Tools/Scripts/print-test-ordering
SUBST_FILES.python+=	third_party/WebKit/Tools/Scripts/run-bindings-tests
SUBST_FILES.python+=	third_party/WebKit/Tools/Scripts/update-test-expectations
SUBST_FILES.python+=	third_party/WebKit/Tools/Scripts/update-w3c-deps
SUBST_FILES.python+=	third_party/WebKit/Tools/Scripts/webkitpy/common/system/executive_unittest.py
SUBST_FILES.python+=	third_party/libxslt/linux/Makefile
SUBST_FILES.python+=	third_party/libxslt/linux/config.log
SUBST_FILES.python+=	third_party/libxslt/linux/libexslt/Makefile
SUBST_FILES.python+=	third_party/libxslt/linux/libxslt/Makefile
SUBST_FILES.python+=	third_party/yasm/source/config/android/Makefile
SUBST_FILES.python+=	third_party/yasm/source/config/ios/Makefile
SUBST_FILES.python+=	third_party/yasm/source/config/linux/Makefile
SUBST_FILES.python+=	third_party/yasm/source/config/mac/Makefile
SUBST_FILES.python+=	third_party/yasm/source/config/openbsd/Makefile
SUBST_FILES.python+=	third_party/yasm/source/config/win/Makefile
SUBST_FILES.python+=	tools/gn/ninja_action_target_writer_unittest.cc
SUBST_FILES.python+=	tools/mb/mb_unittest.py
SUBST_FILES.python+=	tools/memory_inspector/memory_inspector_cli
SUBST_FILES.python+=	tools/usb_gadget/server.py
SUBST_STAGE.python=     pre-build

# Fix building C++11 code
CXXFLAGS+=		-std=gnu++11

do-build:
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${PYTHONBIN} ./tools/gn/bootstrap/bootstrap.py

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/application.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
