# $NetBSD: Makefile,v 1.3 2008/05/14 18:39:12 hoka_adam Exp $
#

DISTNAME=	vlc-snapshot-${VLC_SNAPSHOT_DATE}
PKGNAME=	${DISTNAME:S/snapshot/devel/}
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://nightlies.videolan.org/build/source/trunk-${VLC_SNAPSHOT_DATE}-${VLC_SNAPSHOT_TIME}/
EXTRACT_SUFX=	.tar.bz2

VLC_SNAPSHOT_DATE=	20080507
VLC_SNAPSHOT_TIME=	0014

MAINTAINER=	adam.hoka@gmail.com
HOMEPAGE=	http://nightlies.videolan.org/build/source/trunk-20080507-0014/
COMMENT=	VLC media player development snapshot

CONFLICTS=	vlc-[0-9]* vlc07-[0-9]*

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake perl pkg-config autoconf
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require
USE_LANGUAGES=		c99 c++
USE_DIRS+=		xdg-1.4

WRKSRC=			${WRKDIR}/vlc-0.9.0-git

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--disable-vcd
.endif

BUILDLINK_API_DEPENDS.zlib+=		zlib>=1.2.0
BUILDLINK_API_DEPENDS.vcdimager+=	vcdimager>=0.7.20nb1

CONFIGURE_ARGS+=	--disable-speex # needs unstable 1.1.x branch
CONFIGURE_ARGS+=	--enable-release
CONFIGURE_ARGS+=	--disable-gnomevfs
CONFIGURE_ARGS+=	--disable-gnutls
CONFIGURE_ARGS+=	--with-ffmpeg-zlib
CONFIGURE_ARGS+=	--disable-smb
CONFIGURE_ARGS+=	--disable-mpc
CONFIGURE_ARGS+=	--disable-dca
CONFIGURE_ARGS+=	--enable-cddax
CONFIGURE_ARGS+=	--enable-dvdread
CONFIGURE_ARGS+=	--enable-flac

CONFIGURE_ARGS+=	--enable-live555
CONFIGURE_ARGS+=	--with-live555-tree=${BUILDLINK_PREFIX.liblive}

INSTALLATION_DIRS+=	${PREFIX}/share/vlc/http/dialogs \
			${PREFIX}/share/vlc/http/images \
			${PREFIX}/share/vlc/http/js \
			${PREFIX}/share/vlc/http/old \
			${PREFIX}/share/vlc/http/old/admin \
			${PREFIX}/share/vlc/http/old/vlm \
			${PREFIX}/share/vlc/http/requests \
			${PREFIX}/share/vlc/osdmenu/default \
			${PREFIX}/share/vlc/osdmenu/default/selected \
			${PREFIX}/share/vlc/osdmenu/default/selection \
			${PREFIX}/share/vlc/osdmenu/default/volume \
			${PREFIX}/share/vlc/osdmenu/dvd/selected \
			${PREFIX}/share/vlc/osdmenu/dvd/volume \
			${PREFIX}/share/vlc/osdmenu/dvd/unselect \
			${PREFIX}/share/vlc/osdmenu/dvd/selection \
			${PREFIX}/share/vlc/skins2 \
			${PREFIX}/share/vlc/skins2/fonts

pre-install:
	${INSTALL_DATA} ${WRKSRC}/doc/vlc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/doc/vlc-config.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

ORIGFNT=		/usr/share/fonts/truetype/freefont/FreeSerifBold.ttf
DEFAULT_FONT?=		${X11BASE}/lib/X11/fonts/TTF/DejaVuSans.ttf

SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	post-patch
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_FILES.oss+=	modules/access/v4l.c
SUBST_FILES.oss+=	modules/access/v4l2/v4l2.c
SUBST_FILES.oss+=	modules/audio_output/oss.c
SUBST_FILES.oss+=	modules/gui/pda/pda_interface.c
SUBST_FILES.oss+=	modules/gui/pda/pda.glade
SUBST_FILES.oss+=	test/libvlc/media_list.c
SUBST_FILES.oss+=	po/*.po
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.

SUBST_CLASSES+=         fnt
SUBST_STAGE.fnt=	post-patch
SUBST_SED.fnt=		-e "s,${ORIGFNT},${DEFAULT_FONT},"
SUBST_FILES.fnt=	modules/misc/freetype.c
SUBST_MESSAGE.fnt=	Fixing hardcoded paths.

PLIST_VARS+=		cdda vcd
.if ${OPSYS} != "NetBSD"
PLIST.cdda=		yes
PLIST.vcd=		yes
.endif

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	x_libraries=${PREFIX}/lib
.endif

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libdca/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"

.include "../../devel/libebml/buildlink3.mk"
.include "../../net/liblive/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

.include "../../multimedia/ffmpeg-devel/buildlink3.mk"
.include "../../multimedia/libdvdplay/buildlink3.mk"
.include "../../multimedia/libdvbpsi/buildlink3.mk"
.include "../../multimedia/libdvdnav/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/x264-devel/buildlink3.mk"

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
