# $NetBSD: Makefile,v 1.10 2015/08/17 15:34:47 fhajny Exp $

DISTNAME=	wkhtmltox-0.12.2.1
PKGNAME=	${DISTNAME:S/tox/topdf/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=wkhtmltopdf/}
MASTER_SITES=	http://download.gna.org/wkhtmltopdf/0.12/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	zecrazytux@zecrazytux.net
HOMEPAGE=	http://wkhtmltopdf.org/
COMMENT=	Render HTML into PDF and image formats using QT Webkit
LICENSE=	gnu-lgpl-v3

USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++ c99
USE_TOOLS+=		pax perl pkg-config

HAS_CONFIGURE=		yes

CHECK_PORTABILITY_SKIP=	*

SUBST_CLASSES+=		man
SUBST_STAGE.man=	post-patch
SUBST_MESSAGE.man=	Fixin man page location
SUBST_FILES.man=	src/image/image.pro src/pdf/pdf.pro
SUBST_SED.man=		-e 's,share/man,${PKGMANDIR},g'

CONFIGURE_DIRS=		build/qt
BUILD_DIRS=		build/qt
INSTALL_DIRS=		build/app

CONFIGURE_SCRIPT=	../../qt/configure

.include "../../mk/bsd.prefs.mk"

.if !empty(MACHINE_PLATFORM:MSunOS-*-x86_64)
CONFIGURE_ARGS+=	-platform solaris-g++-64
.elif !empty(MACHINE_PLATFORM:MSunOS-*-i386)
CONFIGURE_ARGS+=	-platform solaris-g++
.endif

CONFIGURE_ARGS+=	\
	--prefix=${WRKSRC}/build/qt						\
	-v -confirm-license -opensource -release -silent			\
	-exceptions -fast -largefile -graphicssystem raster -static

# Features and dependencies
CONFIGURE_ARGS+=	\
	-fontconfig -iconv -openssl -webkit -xmlpatterns -xrender		\
	-system-freetype -system-libjpeg -system-libpng -system-zlib

# Features we don't need/want
CONFIGURE_ARGS+=	\
	-no-3dnow -no-accessibility -no-audio-backend -no-avx -no-cups -no-dbus	\
	-no-declarative -no-glib -no-gstreamer -no-gtkstyle -no-libmng 		\
	-no-libtiff -no-mitshm -no-mmx -no-multimedia -no-nas-sound -no-neon	\
	-no-nis -no-opengl -no-openvg -no-pch -no-phonon -no-phonon-backend	\
	-no-qt3support -no-rpath -no-script -no-scripttools -no-sm		\
	-no-sql-ibase -no-sql-mysql -no-sql-odbc -no-sql-psql -no-sql-sqlite	\
	-no-sql-sqlite2 -no-sse -no-sse2 -no-sse3 -no-sse4.1 -no-sse4.2		\
	-no-ssse3 -no-stl -no-xcursor -no-xfixes -no-xinerama -no-xinput	\
	-no-xkb -no-xrandr -no-xshape -no-xsync -no-javascript-jit

# Bits we don't build
CONFIGURE_ARGS+=	\
	-nomake demos -nomake docs -nomake examples -nomake tests -nomake tools	\
	-nomake translations

# Other tweaks
CONFIGURE_ARGS+=	\
	-D ENABLE_VIDEO=0 -I${PREFIX}/include -I${PREFIX}/include/freetype2

CFLAGS.SunOS+=	-D_XPG6

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}${PREFIX}

PLIST_SUBST+=	LIBVERSION=${PKGVERSION_NOREV:C/([0-9]+\.)([0-9]+\.)([0-9]+)\.[0-9]+/\1\2\3/}

pre-configure:
	${MKDIR} -p ${WRKSRC}/build/app ${WRKSRC}/build/qt

post-build:
	cd ${WRKSRC}/build/app && \
		${SETENV} WKHTMLTOX_VERSION=${PKGVERSION_NOREV} \
	 	../qt/bin/qmake ../../wkhtmltopdf.pro && \
		${BUILD_MAKE_CMD} ${BUILD_TARGET}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
