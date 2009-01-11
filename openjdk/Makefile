# $NetBSD: Makefile,v 1.2 2009/01/11 11:54:25 tnn2 Exp $

DISTNAME=	openjdk-7-ea-src-b42-19_dec_2008
PKGNAME=	openjdk-1.7.0.42.20081230
CATEGORIES=	lang
MASTER_SITES=	http://www.java.net/download/openjdk/jdk7/promoted/b42/
EXTRACT_SUFX=	.zip

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://openjdk.java.net/
COMMENT=	Open-source impl. of the Java Platform, Standard Edition

PKG_DESTDIR_SUPPORT=	user-destdir

DISTFILES=	${DEFAULT_DISTFILES}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

# "hg fclone http://hg.openjdk.java.net/bsd-port/bsd-port/"
PATCHFILES+=	jdk-7-bsd-port-42.20081230.diff.gz
PATCH_SITES+=	http://mx1.nygren.pp.se/distfiles/

ANT=		apache-ant-1.7.1-bin.zip
SITES.${ANT}=	${MASTER_SITE_APACHE:=ant/binaries/}
DISTFILES+=	${ANT}
EXTRACT_ONLY+=	${ANT}
PREPEND_PATH+=	${WRKDIR}/${ANT:S/-bin.zip//}/bin

EXTRACT_USING=	gtar
ICEDTEA=	icedtea-1.8.tar.gz
SITES.${ICEDTEA}=	http://icedtea.classpath.org/download/source/
DISTFILES+=	${ICEDTEA}
EXTRACT_ONLY+=	${ICEDTEA}

BUILD_DEPENDS+=		zip-[0-9]*:../../archivers/zip
BUILD_DEPENDS+=		unzip-[0-9]*:../../archivers/unzip
MAKE_ENV+=		PKGSRC_ZIPEXE=${PREFIX}/bin/zip
MAKE_ENV+=		PKGSRC_UNZIP=${PREFIX}/bin/unzip
MAKE_ENV+=		PKGSRC_UNZIPSFX=${PREFIX}/bin/unzipsfv

NO_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake pax
UNLIMIT_RESOURCES=	datasize stacksize
WRKSRC=			${WRKDIR}/openjdk

BUILDLINK_PASSTHRU_DIRS+=	${ALT_BOOTDIR}
PREPEND_PATH+=			${ALT_BOOTDIR}/bin

MAKE_ENV+=	ALT_BOOTDIR=${ALT_BOOTDIR}
MAKE_ENV+=	ALT_FREETYPE_LIB_PATH=${BUILDLINK_PREFIX.freetype2}/lib
MAKE_ENV+=	ALT_FREETYPE_HEADERS_PATH=${BUILDLINK_PREFIX.freetype2}/include
MAKE_ENV+=	ALT_CUPS_HEADERS_PATH=${BUILDLINK_PREFIX.cups}/include
MAKE_ENV+=	ALT_COMPILER_PATH=${WRAPPER_DIR}/bin
MAKE_ENV+=	ALT_X11_PATH=${X11BASE}

MAKE_ENV+=	ALT_PARALLEL_COMPILE_JOBS=${MAKE_JOBS:U1}

MAKE_ENV+=	HOTSPOT_BUILD_USER=pkgsrc
MAKE_ENV+=	NO_DOCS=true
MAKE_ENV+=	SKIP_COMPARE_IMAGES=true
MAKE_ENV+=	SKIP_FASTDEBUG_BUILD=yes
MAKE_ENV+=	SKIP_DEBUG_BUILD=yes

BUILDDIR=	${WRKSRC}/build/${OPSYS:C/.*BSD/bsd/}-${MACHINE_ARCH:S/i386/i586/:S/x86_64/amd64/}
PLIST_SUBST+=	ARCH=${MACHINE_ARCH:S/x86_64/amd64/}
PLIST_SUBST+=	LOWER_OPSYS=${LOWER_OPSYS}

.include "../../mk/bsd.prefs.mk"
.include "bootstrap.mk"
.include "plugs.mk"

SUBST_CLASSES+=			add-rpaths
SUBST_STAGE.add-rpaths=		pre-build
SUBST_MESSAGE.add-rpaths=	adding X11 run path flags to Makefiles
SUBST_FILES.add-rpaths=		jdk/make/sun/awt/Makefile		\
				jdk/make/sun/awt/mawt.gmk		\
				jdk/make/sun/jawt/Makefile		\
				jdk/make/sun/jdga/Makefile		\
				jdk/make/sun/splashscreen/Makefile	\
				jdk/make/sun/xawt/Makefile
SUBST_SED.add-rpaths=		-e 's|-L$$(OPENWIN_LIB)|-L$$(OPENWIN_LIB) -Wl,-R$$(OPENWIN_LIB)|g'

#post-patch:
#	cd ${WRKSRC} && cp -R ${WRKDIR}/icedtea-1.8/overlays/openjdk/jdk/src/share/classes/com/sun/media/sound jdk/src/share/classes/com/sun/media
#.for icedtea_patch in sound properties copy-plugs
#	cd ${WRKSRC} && patch -s -p1 < ${WRKDIR}/icedtea-1.8/patches/icedtea-${icedtea_patch}.patch
#.endfor

post-build:
	touch ${BUILDDIR}/j2sdk-image/jre/lib/applet/.keep

do-install:
	cd ${BUILDDIR} && mv j2sdk-image openjdk && pax -rwpp openjdk ${DESTDIR}${PREFIX}

.include "../../graphics/freetype2/buildlink3.mk"
BUILDLINK_DEPMETHOD.cups?=	build
.include "../../print/cups/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
