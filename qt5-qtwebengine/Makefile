# $NetBSD$

DISTNAME=	qtwebengine-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtwebengine-${QTVERSION}
COMMENT=	Qt5 WebEngine module

BUILD_DEPENDS+=		gperf-[0-9]*:../../devel/gperf
BUILD_DEPENDS+=		ninja-build-[0-9]*:../../devel/ninja-build

USE_TOOLS+=		bison flex pkg-config sed

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

#.if ${_USE_CWRAPPERS} == "yes"
#BUILDLINK_TRANSFORM+=	R:${WRKSRC}/lib:${QTDIR}/lib
#.else
#BUILDLINK_TRANSFORM+=	rpath:${WRKSRC}/lib:${QTDIR}/lib
#.endif

.if ${OPSYS} == "NetBSD" && ${MACHINE_CPU:U} == "arm"
LDFLAGS+=	-Wl,-no-keep-memory -Wl-reduce-memory
.endif

CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/icu/android/patch_locale.sh
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/icu/source/configure
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/protobuf/post_process_dist.sh
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/swiftshader/third_party/LLVM/utils/buildit/build_llvm
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/xdg-utils/scripts/xdg-terminal
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/third_party/xdg-utils/scripts/xdg-terminal.in
CHECK_PORTABILITY_SKIP+=	src/3rdparty/chromium/v8/tools/run-llprof.sh

SUBST_CLASSES+=		fix-unix
SUBST_STAGE.fix-unix=	pre-configure
SUBST_MESSAGE.fix-unix=	Enabling UNIX support.
SUBST_FILES.fix-unix=	config.tests/*/*.pro
SUBST_SED.fix-unix=	-e 's,linux:SOURCES,unix:SOURCES,'

post-install:
.for i in Qt5WebEngine.pc Qt5WebEngineWidgets.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	ln -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"
.if ${OPSYS} == "Darwin" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
.include "../../devel/libexecinfo/buildlink3.mk"
.endif
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/snappy/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../multimedia/ffmpeg3/buildlink3.mk"
.include "../../multimedia/libvpx/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.if ${OPSYS} != "Darwin"
# alsa pulseaudio
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.endif
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtlocation/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsensors/buildlink3.mk"
.include "../../x11/qt5-qtwebchannel/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=		yes
PYTHON_VERSIONS_ACCEPTED=	27
.include "../../lang/python/tool.mk"
#.include "../../lang/ruby/buildlink3.mk"
#BUILDLINK_DEPMETHOD.${RUBY_BASE}=	build
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
