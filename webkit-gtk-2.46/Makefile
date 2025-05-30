# $NetBSD: Makefile,v 1.240 2022/11/23 16:19:06 adam Exp $
#
# Some environment variables that can help debugging this:
# https://trac.webkit.org/wiki/EnvironmentVariables

DISTNAME=	webkitgtk-2.48.2
PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk/}
CATEGORIES=	www
MASTER_SITES=	https://www.webkitgtk.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.webkitgtk.org/
COMMENT=	GTK port of the WebKit browser engine
LICENSE=	2-clause-bsd AND gnu-lgpl-v2

TOOL_DEPENDS+=	gettext-tools>=0.18:../../devel/gettext-tools
# uses 'unifdef -x1'
TOOL_DEPENDS+=	unifdef-[0-9]*:../../devel/unifdef
TOOL_DEPENDS+=	${PYPKGPREFIX}-gi-docgen-[0-9]*:../../devel/py-gi-docgen

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17
USE_TOOLS+=		automake bash bison flex gdbus-codegen gmake perl pkg-config msgfmt

# this doesn't seem to be using the pkg-config file, which would add this
CXXFLAGS+=	-I${PREFIX}/include/gstreamer-1.0

# Avoid million warnings
CFLAGS+=		-Wno-unused-parameter -Wno-undef
CXXFLAGS+=		-Wno-unused-parameter -Wno-undef

# From Arch Linux:
# JITted code crashes when CET is used
#CFLAGS+=		-fcf-protection=none
#CXXFLAGS+=		-fcf-protection=none

# Enabling -gdwarf-2 hits GNU ar limits on file size.
CTF_SUPPORTED=	no

GCC_REQD+=		11

.include "../../mk/bsd.prefs.mk"

CMAKE_CONFIGURE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=		-DPORT=GTK
CMAKE_CONFIGURE_ARGS+=		-DENABLE_X11_TARGET=ON
CMAKE_CONFIGURE_ARGS+=		-DENABLE_MINIBROWSER=ON
CMAKE_CONFIGURE_ARGS+=		-DENABLE_GAMEPAD=OFF
#CMAKE_CONFIGURE_ARGS+=		-DENABLE_GEOLOCATION=OFF
#CMAKE_CONFIGURE_ARGS+=		-DENABLE_INTROSPECTION=ON
CMAKE_CONFIGURE_ARGS+=		-DENABLE_JOURNALD_LOG=OFF
#CMAKE_CONFIGURE_ARGS+=		-DENABLE_BUBBLEWRAP_SANDBOX=OFF
#CMAKE_CONFIGURE_ARGS+=		-DENABLE_DOCUMENTATION=OFF
CMAKE_CONFIGURE_ARGS+=		-DUSE_SYSTEM_SYSPROF_CAPTURE=NO
CMAKE_CONFIGURE_ARGS+=		-DUSE_SYSPROF_CAPTURE=OFF
CMAKE_CONFIGURE_ARGS+=		-DUSE_GSTREAMER_GL=ON
CMAKE_CONFIGURE_ARGS+=		-DUSE_GSTREAMER_TRANSCODER=OFF
#CMAKE_CONFIGURE_ARGS+=		-DUSE_LIBHYPHEN=OFF
#CMAKE_CONFIGURE_ARGS+=		-DUSE_OPENJPEG=OFF
#CMAKE_CONFIGURE_ARGS+=		-DUSE_SOUP2=ON
CMAKE_CONFIGURE_ARGS+=		-DUSE_LIBBACKTRACE=OFF
CMAKE_CONFIGURE_ARGS+=		-DENABLE_WEBDRIVER=OFF
CMAKE_CONFIGURE_ARGS+=		-DUSE_GTK4=OFF

# required for faking a better user-agent
CMAKE_CONFIGURE_ARGS+=		-DUSER_AGENT_BRANDING="Linux ${MACHINE_ARCH}"

# From OpenBSD ports:
# we don't want an allocation of 1GB, it's above the "default" class ulimit
.if ${MACHINE_ARCH} == "x86_64"
CXXFLAGS+=		-DFIXED_EXECUTABLE_MEMORY_POOL_SIZE_IN_MB=384
.endif
CXXFLAGS+=		-DSTRUCTURE_HEAP_ADDRESS_SIZE_IN_MB=256

PKGCONFIG_OVERRIDE+=	Source/JavaScriptCore/javascriptcoregtk.pc.in

REPLACE_PERL+=		Source/JavaScriptCore/Scripts/*.pl
REPLACE_PERL+=		Source/JavaScriptCore/create_hash_table
REPLACE_PERL+=		Source/WebCore/Scripts/*.pl
REPLACE_PERL+=		Source/WebCore/bindings/scripts/*.pl
REPLACE_PERL+=		Source/WebCore/bindings/scripts/*.pm
REPLACE_PERL+=		Source/WebCore/css/*.pl
REPLACE_PERL+=		Source/WebCore/dom/*.pl
REPLACE_PERL+=		Source/WebCore/make-hash-tools.pl
REPLACE_PERL+=		Source/WebInspectorUI/Scripts/*.pl
REPLACE_PERL+=		Source/WebKit/Scripts/*.pl

REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/*.py
REPLACE_PYTHON+=	Source/JavaScriptCore/Scripts/wkbuiltins/*.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/*.py
REPLACE_PYTHON+=	Source/JavaScriptCore/inspector/scripts/codegen/*.py
REPLACE_PYTHON+=	Source/JavaScriptCore/wasm/*.py
REPLACE_PYTHON+=	Source/JavaScriptCore/yarr/*.py
REPLACE_PYTHON+=	Source/JavaScriptCore/yarr/create_regex_tables
REPLACE_PYTHON+=	Source/JavaScriptCore/yarr/generateYarrCanonicalizeUnicode
REPLACE_PYTHON+=	Source/ThirdParty/ANGLE/src/compiler/translator/*.py
REPLACE_PYTHON+=	Source/ThirdParty/ANGLE/src/libANGLE/*.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/*.py
REPLACE_PYTHON+=	Source/WebCore/css/*.py
REPLACE_PYTHON+=	Source/WebCore/html/parser/create-html-entity-table
REPLACE_PYTHON+=	Source/WebCore/platform/network/create-http-header-name-table
REPLACE_PYTHON+=	Source/WebKit/Scripts/*.py
REPLACE_PYTHON+=	Tools/glib/*.py

REPLACE_BASH+=		Source/JavaScriptCore/postprocess-headers.sh
REPLACE_BASH+=		Source/ThirdParty/ANGLE/adjust-angle-include-paths-rule
REPLACE_BASH+=		Source/ThirdParty/gtest/xcode/Samples/FrameworkSample/runtests.sh
REPLACE_BASH+=		Source/ThirdParty/gtest/xcode/Scripts/runtests.sh
REPLACE_BASH+=		Source/WebKit/Scripts/copy-webcontent-resources-to-private-headers.sh
REPLACE_BASH+=		Source/WebKit/Scripts/process-entitlements.sh
REPLACE_BASH+=		Tools/gtk/install-dependencies

REPLACE_RUBY+=		Source/JavaScriptCore/b3/air/*.rb
REPLACE_RUBY+=		Source/JavaScriptCore/offlineasm/*.rb
REPLACE_RUBY+=		Source/WebCore/domjit/*.rb
REPLACE_RUBY+=		Source/WebInspectorUI/Scripts/*.rb
REPLACE_RUBY+=		Source/WebKit/Scripts/*.rb

SUBST_CLASSES+=		python
SUBST_FILES.python+=	Source/WebInspectorUI/Scripts/copy-user-interface-resources.pl
SUBST_SED.python+=	-e 's,"python3","${PYTHONBIN}",'
SUBST_STAGE.python=	pre-configure
SUBST_MESSAGE.python=	Fixing path to python binary.

.include "../../lang/ruby/rubyversion.mk"
.include "../../lang/ruby/replace.mk"
TOOL_DEPENDS+=	${RUBY_BASE}>=${RUBY_VERSION}:${RUBY_SRCDIR}
CMAKE_CONFIGURE_ARGS+=	-DRUBY_EXECUTABLE=${RUBY}

PYTHON_FOR_BUILD_ONLY=	yes
.include "../../lang/python/application.mk"
CMAKE_CONFIGURE_ARGS+=	-DPYTHON_EXECUTABLE=${PYTHONBIN}

CXXFLAGS.SunOS+=	-fpermissive

# This does not disable optimisations, merely avoids #error if there are none.
CFLAGS+=	-DRELEASE_WITHOUT_OPTIMIZATIONS

# Needed for JavaScript JIT
#NOT_PAX_MPROTECT_SAFE+=	libexec/webkit2gtk-4.1/MiniBrowser
NOT_PAX_MPROTECT_SAFE+=		libexec/webkit2gtk-4.1/WebKitWebProcess
#NOT_PAX_MPROTECT_SAFE+=	libexec/webkit2gtk-4.1/WebKitNetworkProcess
NOT_PAX_MPROTECT_SAFE+=		libexec/webkit2gtk-4.1/jsc

CHECK_PORTABILITY_SKIP+=	Source/JavaScriptCore/Scripts/check-xcfilelists.sh
CHECK_PORTABILITY_SKIP+=	Source/JavaScriptCore/Scripts/create-symlink-to-altroot.sh
CHECK_PORTABILITY_SKIP+=	Source/JavaScriptCore/Scripts/generate-unified-sources.sh
CHECK_PORTABILITY_SKIP+=	Source/WebCore/Scripts/check-xcfilelists.sh
CHECK_PORTABILITY_SKIP+=	Source/WebCore/Scripts/create-symlink-to-altroot.sh
CHECK_PORTABILITY_SKIP+=	Source/WebCore/Scripts/generate-unified-sources.sh
CHECK_PORTABILITY_SKIP+=	Source/WebKit/Scripts/check-xcfilelists.sh
CHECK_PORTABILITY_SKIP+=	Source/WebKit/Scripts/create-symlink-to-altroot.sh
CHECK_PORTABILITY_SKIP+=	Source/WebKit/Scripts/generate-feature-flags-plist.sh
CHECK_PORTABILITY_SKIP+=	Source/WebKit/Scripts/generate-unified-sources.sh
CHECK_PORTABILITY_SKIP+=	Tools/TestWebKitAPI/Scripts/check-xcfilelists.sh
CHECK_PORTABILITY_SKIP+=	Tools/TestWebKitAPI/Scripts/generate-unified-sources.sh

.include "options.mk"

.include "../../audio/flite/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/harfbuzz-icu/buildlink3.mk"
.include "../../fonts/woff2/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/libavif/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/libjxl/buildlink3.mk"
# SkJpegCodec.cpp:210:58: error: 'JCS_RGB565' was not declared in this scope; did you mean 'JCS_RGB'?
JPEG_ACCEPTED=		libjpeg-turbo
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../wip/gst-plugins1-gl/buildlink3.mk"
.include "../../multimedia/gst-plugins1-good/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
#.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../textproc/hyphen/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
#.include "../../x11/gtk4/buildlink3.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
#.include "../../x11/libXdamage/buildlink3.mk"
#.include "../../x11/libXt/buildlink3.mk"
#.include "../../mk/pthread.buildlink3.mk"
#.include "../../mk/atomic64.mk"
# geoclue2
.include "../../mk/bsd.pkg.mk"
