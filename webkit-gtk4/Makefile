# $NetBSD: Makefile,v 1.197 2020/11/06 15:06:49 nia Exp $

DISTNAME=	webkitgtk-2.30.2
PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk4/}
CATEGORIES=	www
MASTER_SITES=	https://www.webkitgtk.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.webkitgtk.org/
COMMENT=	GTK port of the WebKit browser engine
LICENSE=	2-clause-bsd AND gnu-lgpl-v2

# shm_open(3) and shm_unlink(3) appeared in NetBSD 7.0
NOT_FOR_PLATFORM=	NetBSD-[1-6].*-*

TOOL_DEPENDS+=	gettext-tools>=0.18:../../devel/gettext-tools

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
USE_TOOLS+=	automake bash bison flex gmake perl pkg-config msgfmt

# Enabling -gdwarf-2 hits GNU ar limits on file size.
CTF_SUPPORTED=	no

# GCC >= 7.3.0 is required, checked via CMakeLists.txt
GCC_REQD+=		7
USE_GCC_RUNTIME=	yes

# Using ld.gold subverts Pkgsrc wrappers, and this package also crashes buggy
# versions of ld.gold.
CMAKE_CONFIGURE_ARGS+=	-DUSE_LD_GOLD=OFF

PKGCONFIG_OVERRIDE+=	Source/JavaScriptCore/javascriptcoregtk.pc.in
PKGCONFIG_OVERRIDE+=	Source/WebKit/gtk/webkit2gtk-web-extension.pc.in
PKGCONFIG_OVERRIDE+=	Source/WebKit/gtk/webkit2gtk.pc.in

CMAKE_CONFIGURE_ARGS+=		-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=		-DPORT=GTK
CMAKE_CONFIGURE_ARGS+=		-DENABLE_X11_TARGET=ON
CMAKE_CONFIGURE_ARGS+=		-DENABLE_MINIBROWSER=ON
CMAKE_CONFIGURE_ARGS+=		-DENABLE_GEOLOCATION=OFF
CMAKE_CONFIGURE_ARGS+=		-DENABLE_BUBBLEWRAP_SANDBOX=OFF
CMAKE_CONFIGURE_ARGS+=		-DUSE_GSTREAMER_GL=OFF
CMAKE_CONFIGURE_ARGS+=		-DUSE_LIBHYPHEN=OFF
CMAKE_CONFIGURE_ARGS+=		-DUSE_OPENJPEG=OFF
CMAKE_CONFIGURE_ARGS+=		-DUSE_SYSTEMD=OFF
CMAKE_CONFIGURE_ARGS+=		-DUSE_GTK4=ON
CMAKE_CONFIGURE_ARGS+=		-DCMAKE_INSTALL_OLDINCLUDEDIR=${PREFIX}/include

REPLACE_PERL+=	Source/JavaScriptCore/Scripts/*.pl
REPLACE_PERL+=	Source/JavaScriptCore/create_hash_table
REPLACE_PERL+=	Source/WebCore/Scripts/*.pl
REPLACE_PERL+=	Source/WebCore/bindings/scripts/*.pl
REPLACE_PERL+=	Source/WebCore/bindings/scripts/*.pm
REPLACE_PERL+=	Source/WebCore/css/*.pl
REPLACE_PERL+=	Source/WebCore/dom/*.pl
REPLACE_PERL+=	Source/WebCore/make-hash-tools.pl
REPLACE_PERL+=	Source/WebInspectorUI/Scripts/*.pl
REPLACE_PERL+=	Source/WebKit/Scripts/*.pl
REPLACE_PERL+=	Source/cmake/tools/scripts/*.pl

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
REPLACE_PYTHON+=	Source/ThirdParty/gtest/scripts/*.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/test/*.py
REPLACE_PYTHON+=	Source/ThirdParty/gtest/xcode/Scripts/*.py
REPLACE_PYTHON+=	Source/WebCore/css/*.py
REPLACE_PYTHON+=	Source/WebCore/html/parser/create-html-entity-table
REPLACE_PYTHON+=	Source/WebCore/platform/network/create-http-header-name-table
REPLACE_PYTHON+=	Source/WebKit/Scripts/*.py
REPLACE_PYTHON+=	Tools/glib/*.py
REPLACE_PYTHON+=	Tools/gtkdoc/generate-gtkdoc

REPLACE_BASH+=		Source/JavaScriptCore/postprocess-headers.sh
REPLACE_BASH+=		Source/ThirdParty/ANGLE/adjust-angle-include-paths-rule
REPLACE_BASH+=		Source/ThirdParty/gtest/xcode/Samples/FrameworkSample/runtests.sh
REPLACE_BASH+=		Source/ThirdParty/gtest/xcode/Scripts/runtests.sh
REPLACE_BASH+=		Source/WebKit/Scripts/copy-webcontent-resources-to-private-headers.sh
REPLACE_BASH+=		Source/WebKit/Scripts/generate-https-upgrade-database.sh
REPLACE_BASH+=		Source/WebKit/Scripts/process-entitlements.sh
REPLACE_BASH+=		Tools/gtk/install-dependencies

REPLACE_RUBY+=		Source/JavaScriptCore/b3/air/*.rb
REPLACE_RUBY+=		Source/JavaScriptCore/offlineasm/*.rb
REPLACE_RUBY+=		Source/WebCore/Scripts/*.rb
REPLACE_RUBY+=		Source/WebCore/domjit/*.rb
REPLACE_RUBY+=		Source/WebInspectorUI/Scripts/*.rb
REPLACE_RUBY+=		Source/WebKit/Scripts/*.rb

SUBST_CLASSES+=		python
SUBST_FILES.python+=	Source/WebInspectorUI/Scripts/copy-user-interface-resources.pl
SUBST_SED.python+=	-e 's,\(.\)python.;,\1${PYTHONBIN}\1;,'
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

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)
CXXFLAGS+=	-Wno-c++11-narrowing
.endif

# This does not disable optimisations, merely avoids #error if there are none.
CFLAGS+=	-DRELEASE_WITHOUT_OPTIMIZATIONS

# Needed for JavaScript JIT
NOT_PAX_MPROTECT_SAFE+=	libexec/webkit2gtk-4.0/WebKitWebProcess
NOT_PAX_MPROTECT_SAFE+=	libexec/webkit2gtk-4.0/jsc

.include "options.mk"


.if ${OPSYS} == "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=	-DENABLE_X11_TARGET=OFF
CMAKE_CONFIGURE_ARGS+=	-DENABLE_QUARTZ_TARGET=ON
CMAKE_CONFIGURE_ARGS+=	-DENABLE_GRAPHICS_CONTEXT_GL=OFF
.endif

BUILDLINK_API_DEPENDS.glib2+= glib2>=2.32.1
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/harfbuzz-icu/buildlink3.mk"
.include "../../fonts/woff2/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
BUILDLINK_API_DEPENDS.png+= png>=1.5.1beta08
.include "../../graphics/png/buildlink3.mk"
BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.0.3
.include "../../multimedia/gstreamer1/buildlink3.mk"
BUILDLINK_API_DEPENDS.gst-plugins1-base+=	gst-plugins1-base>=1.0.3
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
BUILDLINK_API_DEPENDS.libsoup+= libsoup>=2.42.2nb3
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/libtasn1/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../wip/gtk4/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
