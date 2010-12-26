# $NetBSD: Makefile,v 1.4 2010/12/26 05:01:24 davesainty Exp $
#

DISTNAME=	xbmc-9.11
PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xbmc/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://xbmc.org/
COMMENT=	Software media player and entertainment hub for digital media
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/xbmc-9.11
USE_TOOLS+=	automake
USE_TOOLS+=	bash
USE_TOOLS+=	gawk
USE_TOOLS+=	gmake
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

#REPLACE_INTERPRETER+=	bash
#REPLACE.bash.old=	/bin/sh
#REPLACE.bash.new=	${TOOLS_PATH.bash}
#REPLACE_FILES.bash=	configure

SUBST_CLASSES+=			fix-interpreter
SUBST_STAGE.fix-interpreter=	configure
SUBST_MESSAGE.fix-interpreter=	Forcing use of bash
SUBST_FILES.fix-interpreter=	configure
SUBST_SED.fix-interpreter=	-e 's,^/bin/sh,${TOOLS_PATH.bash},'

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-external-libraries

LDFLAGS+=	-L ${BUILDLINK_PREFIX.samba}/lib/samba
LDFLAGS+=	-Wl,-rpath,${BUILDLINK_PREFIX.samba}/lib/samba

PKGCONFIG_OVERRIDE+=	xbmc/cores/dvdplayer/Codecs/libdvd/libdvdread/misc/dvdread.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/cores/dvdplayer/Codecs/libdvd/libdvdcss/src/libdvdcss.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/cores/dvdplayer/Codecs/libdvd/libdvdnav/misc/dvdnavmini.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/cores/dvdplayer/Codecs/libdvd/libdvdnav/misc/dvdnav.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/cores/dvdplayer/Codecs/libmpeg2/libmpeg2/libmpeg2.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/cores/dvdplayer/Codecs/libmpeg2/libmpeg2/convert/libmpeg2convert.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/cores/dvdplayer/Codecs/libdts/libdts/libdts.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/cores/paplayer/SIDCodec/libsidplay/unix/libsidplay2.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/cores/paplayer/vorbisfile/ogg/ogg.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/cores/paplayer/vorbisfile/libvorbis/vorbisenc.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/cores/paplayer/vorbisfile/libvorbis/vorbis.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/cores/paplayer/vorbisfile/libvorbis/vorbisfile.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/cores/paplayer/FLACCodec/flac-1.2.1/src/libFLAC++/flac++.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/cores/paplayer/FLACCodec/flac-1.2.1/src/libFLAC/flac.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/lib/libmms/libmms_win32/pkgconfig/libmms.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/lib/libass/libass.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/lib/libcdio/libcdio/libiso9660++.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/lib/libcdio/libcdio/libcdio_cdda.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/lib/libcdio/libcdio/libcdio.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/lib/libcdio/libcdio/libcdio++.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/lib/libcdio/libcdio/libcdio_paranoia.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/lib/libcdio/libcdio/libiso9660.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/lib/libcdio/libcdio/libudf.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/lib/libcurl/curl-7.19.0/libcurl.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/lib/libsamplerate/samplerate.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/visualizations/XBMCProjectM/libprojectM/libprojectM.pc.in
PKGCONFIG_OVERRIDE+=	xbmc/visualizations/Goom/goom2k4-0/libgoom2.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../databases/mysql5-client/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../net/libmms/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../net/samba/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../textproc/enca/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/hal/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../audio/liba52/buildlink3.mk"
.include "../../audio/libdca/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
