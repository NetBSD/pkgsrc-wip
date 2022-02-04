# $NetBSD: Makefile,v 1.234 2021/12/08 16:04:19 adam Exp $

DISTNAME=	wine-7.0
CATEGORIES=	emulators
MASTER_SITES=	https://dl.winehq.org/wine/source/${PKGVERSION_NOREV}/
MASTER_SITES+=	https://dl.winehq.org/wine/source/${PKGVERSION_NOREV:R}/
MASTER_SITES+=	http://mirrors.ibiblio.org/wine/source/${PKGVERSION_NOREV}/
MASTER_SITES+=	http://mirrors.ibiblio.org/wine/source/${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.winehq.org/
COMMENT=	Compatibility layer for running Microsoft Windows applications
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison flex gmake mktemp msgfmt perl pkg-config
GNU_CONFIGURE=	yes

CHECK_SHLIBS_SUPPORTED=	no

REPLACE_PERL+=	tools/winemaker/winemaker
REPLACE_PERL+=	tools/winedump/function_grep.pl

ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64

UNLIMIT_RESOURCES=	datasize

CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--without-capi
CONFIGURE_ARGS+=	--without-gssapi
CONFIGURE_ARGS+=	--without-krb5
CONFIGURE_ARGS+=	--without-opencl
CONFIGURE_ARGS+=	--without-udev
CONFIGURE_ARGS+=	--without-v4l2
CONFIGURE_ARGS+=	--without-vkd3d

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		desktop lp32 lp64 oss

.if ${MACHINE_ARCH} == "x86_64"
PLIST.lp64=		yes
WINE32_BUILD_DIR=	${WRKDIR}/wine32
WINE64_BUILD_DIR=	${WRKDIR}/wine64
BUILD_DIRS=		${WINE64_BUILD_DIR}
INSTALL_DIRS=		${WINE32_BUILD_DIR} ${WINE64_BUILD_DIR}
NOT_PAX_MPROTECT_SAFE+=	bin/wine64
.else
PLIST.lp32=		yes
NOT_PAX_MPROTECT_SAFE+=	bin/wine
.endif

.if ${OPSYS} == "NetBSD"
.  if !empty(OS_VERSION:M[0-8].*)
# Disable new_dtags as NetBSD versions prior to 9.0 don't honor DT_RUNPATH
CONFIGURE_ENV+=		ac_cv_cflags__Wl___enable_new_dtags=no
.  endif
# gethostbyname_r is in libc, but has a different calling convention
CONFIGURE_ENV+=		wine_cv_linux_gethostbyname_r_6=no
.endif

# OSSv4 is required (oss_sysinfo.numaudioengies is cheched by configure)
BUILTIN_FIND_GREP.H_SOUNDCARD=	numaudioengines
.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
PLIST.oss=		yes
LDFLAGS+=		${LIBOSSAUDIO}
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	dlls/wineoss.drv/mmdevdrv.c
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.else
CONFIGURE_ARGS+=	--without-oss
.endif

# Fix warning due to _FORTIFY_SOURCE being redefined
CONFIGURE_ENV+=		ac_cv_c_fortify_enabled=no

.if ${MACHINE_ARCH} == "x86_64"
pre-configure:
	${RUN} ${MKDIR} -p ${WINE32_BUILD_DIR}
	${RUN} ${MKDIR} -p ${WINE64_BUILD_DIR}

do-configure:
	${RUN}${_ULIMIT_CMD}						\
	cd ${WINE64_BUILD_DIR} &&					\
	${PKGSRC_SETENV} ${_CONFIGURE_SCRIPT_ENV}			\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS}			\
			${WRKSRC}/${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} --enable-win64

.PHONY: do-configure-wine32
do-configure-wine32:
	${RUN}${_ULIMIT_CMD}						\
	cd ${WINE32_BUILD_DIR} &&					\
	${PKGSRC_SETENV} ${_CONFIGURE_SCRIPT_ENV}			\
		${CONFIG_SHELL} ${CONFIG_SHELL_FLAGS}			\
			${WRKSRC}/${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} --with-wine64=${WINE64_BUILD_DIR} --without-freetype

.PHONY: do-build-wine32
do-build-wine32: do-configure-wine32
	${RUN}${_ULIMIT_CMD}						\
	cd ${WINE32_BUILD_DIR} &&					\
	${BUILD_MAKE_CMD} ${BUILD_TARGET}

post-build: do-build-wine32
.endif	

# Wine will use system frameworks on Darwin.
.if ${OPSYS} != "Darwin"
PLIST.desktop=	yes
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.endif

.include "options.mk"
.include "../../audio/faudio/buildlink3.mk"
.include "../../audio/gsm/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
