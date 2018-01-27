# $NetBSD: Makefile,v 1.1 2015/02/23 16:11:05 leot1990 Exp $
#

DISTNAME=	phantomjs-2.0.0-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	www
MASTER_SITES=	http://bitbucket.org/ariya/phantomjs/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.phantomjs.org/
COMMENT=	Headless WebKit with JavaScript API
LICENSE=	modified-bsd

# XXX: when updating this package it is a nice idea to import the
# x11/qt5-qtbase/patches and x11/qt5-webkit/patches. The following regular
# expression can help in order to easily adapt them:
#
#  sed -E 's;(---|\+\+\+) ;\1 src/qt/qtbase/;'
#  sed -E 's;(---|\+\+\+) ;\1 src/qt/qtwebkit/;'

WRKSRC=		${WRKDIR}/${DISTNAME:S/-source//}
USE_LANGUAGES=	c c++ c99
USE_TOOLS+=	bash bison flex gmake perl pkg-config sed
REPLACE_PERL+=	src/qt/qtwebkit/Source/WebKit2/Scripts/generate-forwarding-headers.pl

CHECK_PORTABILITY_SKIP=		src/qt/config.tests/mac/dwarf2.test src/qt/configure
CHECK_PORTABILITY_SKIP+=	src/breakpad/src/third_party/protobuf/protobuf/post_process_dist.sh

.include "../../mk/bsd.prefs.mk"

NOT_FOR_PLATFORM+=	SunOS-*-x86_64

CONFIGURE_ARGS+=	--qtdeps=system -no-rpath 
CONFIGURE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

CFLAGS.NetBSD+=		-D_NETBSD_SOURCE
CFLAGS.SunOS+=		-D_XPG6

MAKE_ENV+=		QTDIR=${WRKSRC}/src/qt
INSTALLATION_DIRS+=	bin share/doc/phantomjs share/examples/phantomjs

PHANTOMJS_WEBKIT_DISABLE+=	use_glib
PHANTOMJS_WEBKIT_DISABLE+=	use_gstreamer
PHANTOMJS_WEBKIT_DISABLE+=	use_gstreamer010
PHANTOMJS_WEBKIT_DISABLE+=	use_native_fullscreen_video
PHANTOMJS_WEBKIT_DISABLE+=	legacy_web_audio
PHANTOMJS_WEBKIT_DISABLE+=	web_audio
PHANTOMJS_WEBKIT_DISABLE+=	video
PHANTOMJS_WEBKIT_DISABLE+=	gamepad

pre-configure:
	${SED}	-e 's:@LOCALBASE@:${LOCALBASE}:g' \
		-e 's:@X11BASE@:${X11BASE}:g' \
		-e 's:@X11PREFIX@:${X11PREFIX}:g' \
		-e 's:@LIBTOOL@:${LIBTOOL:Q}:g' \
		-e 's:@CC@:${CC:Q}:g' \
		-e 's:@CXX@:${CXX:Q}:g' \
		-e 's:@LDFLAGS@:${LDFLAGS:Q}:g' \
		-e 's:@CFLAGS@:${CFLAGS:Q}:g' \
		-e 's:@CXXFLAGS@:${CXXFLAGS:Q}:g' \
		-e 's:@SYS_LIBS@:${SYS_LIBS:Q}:g' \
		-e 's:@LEX@:${LEX}:g' \
		-e 's:@YACC@:${TOOLS_CMDLINE_YACC:Q}:g' \
		-e 's:@AR@:${AR:Q}:g' \
		-e 's:@MKDIR@:${MKDIR}:g' \
		-e 's:@LIBQT@:${LIBQT:Q}:g' \
		-e 's:@PTHREAD_LDFLAGS@:${PTHREAD_LDFLAGS:Q}:g' \
		-e 's:@PTHREAD_LIBS@:${PTHREAD_LIBS:Q}:g' \
		-e 's:@COMPILER_RPATH_FLAG@:${COMPILER_RPATH_FLAG}:g' \
		-e 's:@QMAKE_RANLIB@:${QMAKE_RANLIB:Q}:g' \
		${FILESDIR}/qmake.conf > ${WRKSRC}/qmake.conf
	for dir in ${WRKSRC}/src/qt/qtbase/mkspecs/*; do \
		cp ${WRKSRC}/qmake.conf $${dir}; \
		rm -f $${dir}/*.orig; \
	done

do-configure:
	cd ${WRKSRC}/src/qt && ${SETENV} ${CONFIGURE_ENV} ./preconfig.sh ${CONFIGURE_ARGS}

do-build: ${WRKDIR}/.build_qt_done
	cd ${WRKSRC} && ./src/qt/qtbase/bin/qmake
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} ${BUILD_TARGET}

${WRKDIR}/.build_qt_done:
	# Build qtbase
	cd ${WRKSRC}/src/qt/qtbase && ${BUILD_MAKE_CMD} ${BUILD_TARGET}
	# Build qtwebkit
	cd ${WRKSRC}/src/qt/qtwebkit && \
	${WRKSRC}/src/qt/qtbase/bin/qmake \
	    "WEBKIT_CONFIG -= ${PHANTOMJS_WEBKIT_DISABLE}"
#
# FIXME: during the linking phase of jsc and phantomjs there are various LIBS
# with .a extension but in LIBS they have the .la extension.
#
#	${CP} ${WRKSRC}/src/qt/qtwebkit/Source/JavaScriptCore/Makefile.jsc \
#	    ${WRKSRC}/src/qt/qtwebkit/Source/JavaScriptCore/Makefile.jsc.orig
#	${CP} ${WRKSRC}/src/Makefile.phantomjs \
#	    ${WRKSRC}/src/Makefile.phantomjs.orig
#	${SED} -e '/LIBS/ s/\.la/.a/g' \
#	    ${WRKSRC}/src/qt/qtwebkit/Source/JavaScriptCore/Makefile.jsc.orig \
#	    > ${WRKSRC}/src/qt/qtwebkit/Source/JavaScriptCore/Makefile.jsc
#	${SED} -e '/LIBS/ s/\.la/.a/g' \
#	    ${WRKSRC}/src/Makefile.phantomjs.orig \
#	    > ${WRKSRC}/src/Makefile.phantomjs
#	${RM} -f ${WRKSRC}/src/qt/qtwebkit/Source/JavaScriptCore/Makefile.jsc.orig \
#	    ${WRKSRC}/src/Makefile.phantomjs.orig
	cd ${WRKSRC}/src/qt/qtwebkit && ${BUILD_MAKE_CMD} ${BUILD_TARGET}
	${TOUCH} ${WRKDIR}/.build_qt_done

do-install:
	cd ${WRKSRC} && (\
		${INSTALL_PROGRAM} bin/phantomjs \
			${DESTDIR}${PREFIX}/bin/; \
		${INSTALL_DATA} examples/* \
			${DESTDIR}${PREFIX}/share/examples/phantomjs; \
		${INSTALL_DATA} ChangeLog LICENSE.BSD README.md third-party.txt \
			${DESTDIR}${PREFIX}/share/doc/phantomjs \
		)

.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY=			yes
.include "../../lang/python/tool.mk"
.include "../../lang/ruby/buildlink3.mk"
BUILDLINK_DEPMETHOD.${RUBY_BASE}=	build
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
