# $NetBSD: Makefile,v 1.262 2024/11/05 12:19:30 triaxx Exp $

DISTNAME=	wine-9.0
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	https://dl.winehq.org/wine/source/${PKGVERSION_NOREV}/
MASTER_SITES+=	http://mirrors.ibiblio.org/wine/source/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.winehq.org/
COMMENT=	Compatibility layer for running Microsoft Windows applications
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_TOOLS+=	bison flex gmake mktemp msgfmt perl pkg-config
GNU_CONFIGURE=	yes

REPLACE_PERL+=	tools/winemaker/winemaker
REPLACE_PERL+=	tools/winedump/function_grep.pl

CHECK_PIE_SUPPORTED=	no
CHECK_SHLIBS_SUPPORTED=	no

ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64

UNLIMIT_RESOURCES=	datasize

CONFIGURE_ARGS+=	--disable-tests
CONFIGURE_ARGS+=	--without-capi
CONFIGURE_ARGS+=	--without-gphoto
CONFIGURE_ARGS+=	--without-gssapi
CONFIGURE_ARGS+=	--without-hal
# LDAP causes build failures on NetBSD 9.99.x and newer.
CONFIGURE_ARGS+=	--without-ldap
CONFIGURE_ARGS+=	--without-krb5
CONFIGURE_ARGS+=	--without-opencl
CONFIGURE_ARGS+=	--without-udev
CONFIGURE_ARGS+=	--without-v4l2
CONFIGURE_ARGS+=	--without-vkd3d
CONFIGURE_ARGS+=	--without-vulkan

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		desktop lp32 lp64 oss

.if ${MACHINE_ARCH} == "x86_64"
TOOL_DEPENDS+=		mingw-w64-[0-9]*:../../cross/mingw-w64
CONFIGURE_ARGS+=	--enable-archs=i386,x86_64
MINGW32_32=		i686-w64-mingw32
MINGW32_64=		x86_64-w64-mingw32
MINGW32_32_PATH=	${CROSSBASE}/${MINGW32_32}/bin
MINGW32_64_PATH=	${CROSSBASE}/${MINGW32_64}/bin

SUBST_CLASSES+=		wb
SUBST_STAGE.wb=		pre-configure
SUBST_MESSAGE.wb=	Setting the path of mingw32 compilers in winebuild.
SUBST_FILES.wb+=	tools/winebuild/utils.c
SUBST_VARS.wb+=		MINGW32_32_PATH MINGW32_64_PATH

pre-configure:
	${LN} -s ${MINGW32_32_PATH}/${MINGW32_32}-gcc \
		${TOOLS_DIR}/bin/${MINGW32_32}-gcc
	${LN} -s ${MINGW32_64_PATH}/${MINGW32_64}-gcc \
		${TOOLS_DIR}/bin/${MINGW32_64}-gcc
.endif
NOT_PAX_MPROTECT_SAFE+=	bin/wine

.if ${OPSYS} == "NetBSD"
.  if ${OPSYS_VERSION} < 090000
# Disable new_dtags as NetBSD versions prior to 9.0 don't honor DT_RUNPATH
CONFIGURE_ENV+=		ac_cv_cflags__Wl___enable_new_dtags=no
.  endif
# gethostbyname_r is in libc, but has a different calling convention
CONFIGURE_ENV+=		wine_cv_linux_gethostbyname_r_6=no
.endif

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
PLIST.oss=		yes
LDFLAGS+=		${LIBOSSAUDIO}
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	dlls/wineoss.drv/oss.c
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.else
CONFIGURE_ARGS+=	--without-oss
.endif

# Fix warning due to _FORTIFY_SOURCE being redefined
CONFIGURE_ENV+=		ac_cv_c_fortify_enabled=no

# Wine will use system frameworks on Darwin.
.if ${OPSYS} != "Darwin"
PLIST.desktop=		yes
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
.include "../../net/libpcap/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
