# $NetBSD: Makefile,v 1.7 2015/01/09 14:03:41 fhajny Exp $
#

DISTNAME=	phantomjs-1.9.8-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	www
MASTER_SITES=	http://bitbucket.org/ariya/phantomjs/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://www.phantomjs.org/
COMMENT=	Headless WebKit with JavaScript API
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/${DISTNAME:S/-source//}
USE_LANGUAGES=	c c++ c99
USE_TOOLS+=	bash gmake

CHECK_PORTABILITY_SKIP=		src/qt/config.tests/mac/dwarf2.test src/qt/configure
CHECK_PORTABILITY_SKIP+=	src/breakpad/src/third_party/protobuf/protobuf/post_process_dist.sh

.include "../../mk/bsd.prefs.mk"

NOT_FOR_PLATFORM+=	SunOS-*-x86_64

CONFIGURE_ARGS+=	--qt-config -no-rpath --jobs ${MAKE_JOBS}
CONFIGURE_ENV+=		MACHINE_ARCH=${MACHINE_ARCH}

CFLAGS.SunOS+=		-D_XPG6

MAKE_ENV+=		QTDIR=${WRKSRC}/src/qt
INSTALLATION_DIRS+=	bin share/doc/phantomjs share/examples/phantomjs

post-extract:
	${MKDIR} -p ${WRKSRC}/src/qt/mkspecs/solaris-g++
	${INSTALL_DATA} ${FILESDIR}/qplatformdefs.h ${WRKSRC}/src/qt/mkspecs/solaris-g++

pre-configure:
	sed	-e 's:@LOCALBASE@:${LOCALBASE}:g' \
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
	for dir in ${WRKSRC}/src/qt/mkspecs/*; do \
		cp ${WRKSRC}/qmake.conf $${dir}; \
		rm -f $${dir}/*.orig; \
	done

do-configure:
	cd ${WRKSRC}/src/qt && ${SETENV} ${CONFIGURE_ENV} ./preconfig.sh ${CONFIGURE_ARGS}

do-build: ${WRKDIR}/.build_qt_done
	cd ${WRKSRC} && ./src/qt/bin/qmake
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} ${BUILD_TARGET}

${WRKDIR}/.build_qt_done:
	cd ${WRKSRC}/src/qt && ${BUILD_MAKE_CMD} ${BUILD_TARGET}
	cd ${WRKSRC}/src/qt/src/plugins/codecs && ${BUILD_MAKE_CMD} ${BUILD_TARGET}
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

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
