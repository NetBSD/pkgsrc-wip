# $NetBSD: Makefile,v 1.8 2011/05/22 16:17:58 ftigeot Exp $

VER=			2011-05-22
DISTNAME=		libreoffice-${VER}
PKGNAME=		libreoffice-${VER:S/-//g}
CATEGORIES=		misc
#MASTER_SITES=	http://download.documentfoundation.org/libreoffice/src/
MASTER_SITES=	http://dl.wolfpond.org/libreoffice/ \
		http://download.go-oo.org/src/ \
		http://www.numbertext.org/linux/

MAINTAINER=		ftigeot@wolfpond.org
HOMEPAGE=		http://www.libreoffice.org/
COMMENT=		Office productivity suite
LICENSE=		gnu-lgpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

DIST_SUBDIR=	libreoffice


LO_BOOTSTRAP=	libreoffice-bootstrap-${VER}
LO_COMPONENTS=	artwork base calc components extensions extras \
		filters help impress libs-core libs-extern \
		libs-extern-sys libs-gui postprocess sdk testing \
		ure writer

MORE_DISTFILES= \
	1756c4fa6c616ae15973c104cd8cb256-Adobe-Core35_AFMs-314.tar.gz \
	881af2b7dca9b8259abbca00bbbc004d-LinLibertineG-20110101.zip \
	f02578f5218f217a9f20e9c30e119c6a-boost_1_44_0.tar.bz2 \
	d70951c80dabecc2892c919ff5d07172-db-4.7.25.NC-custom.tar.gz \
	37282537d0ed1a087b1c8f050dc812d9-dejavu-fonts-ttf-2.32.zip \
	35efabc239af896dfb79be7ebdd6e6b9-gentiumbasic-fonts-1.10.zip \
	48a9f787f43a09c0a9b7b00cd1fddbbf-hyphen-2.7.1.tar.gz \
	ca4870d899fd7e943ffc310a5421ad4d-liberation-fonts-ttf-1.06.0.20100721.tar.gz \
	763bb9b14eec5ba9a533d7a9279301db-libvisio-0.0.0.tar.gz \
	7a0dcb3fe1e8c7229ab4fb868b7325e6-mdds_0.5.2.tar.bz2 \
	067201ea8b126597670b5eff72e1f66c-mythes-1.2.0.tar.gz \
	fdb27bfe2dbe2e7b57ae194d9bf36bab-SampleICC-1.3.2.tar.gz

DISTFILES=		${LO_BOOTSTRAP}.tar.bz2
EXTRACT_ONLY=	${LO_BOOTSTRAP}.tar.bz2
.for component in ${LO_COMPONENTS}
DISTFILES+=		libreoffice-${component}-${VER}.tar.bz2
EXTRACT_ONLY+=	libreoffice-${component}-${VER}.tar.bz2
.endfor

.for md in ${MORE_DISTFILES}
DISTFILES+=		${md}
.endfor

# tar: Invalid header, starting valid header search.
EXTRACT_USING=		gtar

WRKSRC=		${WRKDIR}/${LO_BOOTSTRAP}


BUILD_DEPENDS+=		cppunit>1.12:../../devel/cppunit
BUILD_DEPENDS+=		gperf-[0-9]*:../../devel/gperf
BUILD_DEPENDS+=		hunspell>=1.2.8:../../textproc/hunspell
BUILD_DEPENDS+=		p5-Archive-Zip-[0-9]*:../../archivers/p5-Archive-Zip
BUILD_DEPENDS+=		zip-[0-9]*:../../archivers/zip

# dmake scripts use relative path with -rpath-link ld arguments, which
# is a no-go with normal pkgsrc wrappers.
# dmake is slowly beeing removed from the LibreOffice build process
# and this option will hopefully become unneeded in the future
WRAPPER_SKIP_TRANSFORM=yes

.include "../../mk/bsd.prefs.mk"

USE_LANGUAGES+=		c c++

CONFLICTS+=		staroffice-[0-9]*
CONFLICTS+=		openoffice-[0-9]*
CONFLICTS+=		openoffice2-[0-9]*
CONFLICTS+=		openoffice-bin-[0-9]*
CONFLICTS+=		openoffice2-bin-[0-9]*
CONFLICTS+=		openoffice3-[0-9]*
CONFLICTS+=		openoffice3-bin-[0-9]*
CONFLICTS+=		openoffice-linux-[0-9]*
CONFLICTS+=		libreoffice3-bin-[0-9]*


USE_TOOLS+=		automake bash bison gmake perl pkg-config unzip
PTHREAD_OPTS+=		require

HAS_CONFIGURE=		yes

CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX}/${PKGNAME}
CONFIGURE_ARGS+=	--disable-epm
CONFIGURE_ARGS+=	--disable-mozilla
CONFIGURE_ARGS+=	--disable-neon
CONFIGURE_ARGS+=	--disable-nss-module
CONFIGURE_ARGS+=	--disable-odk
CONFIGURE_ARGS+=	--disable-opengl
CONFIGURE_ARGS+=	--disable-systray
CONFIGURE_ARGS+=	--with-alloc=system
CONFIGURE_ARGS+=	--with-fonts
CONFIGURE_ARGS+=	--with-max-jobs=${MAKE_JOBS}
CONFIGURE_ARGS+=	--with-system-headers
CONFIGURE_ARGS+=	--with-system-libs
CONFIGURE_ARGS+=	--with-system-libtextcat
CONFIGURE_ARGS+=	--with-system-python
CONFIGURE_ARGS+=	--with-vendor="The LibreOffice pkgsrc team"
CONFIGURE_ARGS+=	--without-java
CONFIGURE_ARGS+=	--without-system-altlinuxhyph
CONFIGURE_ARGS+=	--without-system-boost
CONFIGURE_ARGS+=	--without-system-db
CONFIGURE_ARGS+=	--without-system-jars
CONFIGURE_ARGS+=	--without-system-mdds
CONFIGURE_ARGS+=	--without-system-mythes

# Some LibreOffice build scripts do strange things with library paths
# and fail with the pkgsrc environment
# Preset LD_LIBRARY_PATH to sane defaults and avoid complicating them
# further
LIBPATH=				${BUILDLINK_DIR}/lib:${WRKSRC}/desktop/unxdfly.pro/lib:${WRKSRC}/desktop/unxnbsd.pro/lib
SUBST_CLASSES+=			libpath
SUBST_STAGE.libpath=	pre-configure
SUBST_FILES.libpath=	set_soenv.in
SUBST_SED.libpath=		-e 's,@LIBPATH@,${LIBPATH},g'
SUBST_MESSAGE.libpath=	Fixing library path for dmake scripts

LO_PROGRAMS=	sbase scalc sdraw simpress smath soffice swriter

post-extract:
	${MKDIR} -p ${WRKSRC}/clone
	${MKDIR} -p ${WRKSRC}/src
.for comp in ${LO_COMPONENTS}
	${MV} ${WRKDIR}/libreoffice-${comp}-${VER} ${WRKSRC}/clone/${comp}
.endfor
.for md in ${MORE_DISTFILES}
	${LN} -s ${DISTDIR}/${DIST_SUBDIR}/${md} ${WRKSRC}/src/${md}
.endfor
	${TOUCH} ${WRKSRC}/clone/repos_changed

do-configure:
	cd ${WRKSRC} && ./autogen.sh ${CONFIGURE_ARGS}

post-configure:
	cd ${WRKSRC} && ./bin/create_bootstrap_links
	${TOUCH} ${WRKSRC}/src.downloaded

post-install:
	${MKDIR} -p ${DESTDIR}${PREFIX}/bin
	for f in ${LO_PROGRAMS}; do \
		${LN} -s ${DESTDIR}${PREFIX}/${PKGNAME}/program/$$f ${DESTDIR}${PREFIX}/bin/$$f; \
	done


.include "../../converters/libwpd/buildlink3.mk"
.include "../../converters/libwpg/buildlink3.mk"
.include "../../converters/libwps/buildlink3.mk"
.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/cppunit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../graphics/sane-backends/buildlink3.mk"
.include "../../graphics/vigra/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../math/lp_solve/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../print/cups/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/redland/buildlink3.mk"
.include "../../wip/libtextcat/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
