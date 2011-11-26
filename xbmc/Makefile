# $NetBSD: Makefile,v 1.5 2011/11/26 12:45:15 ryo-on Exp $
#

DISTNAME=	xbmc-10.1
CATEGORIES=	multimedia
MASTER_SITES=	http://mirrors.xbmc.org/releases/source/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://xbmc.org/
COMMENT=	Software media player and entertainment hub for digital media
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

EXTRACT_USING=		bsdtar

USE_TOOLS+=		pkg-config automake
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

DEPENDS+=		gettext-tools>=0.18.1.1:../../devel/gettext-tools

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./configure
CONFIGURE_ARGS+=	--prefix=${DESTDIR}${PREFIX}
CONFIGURE_ARGS+=	--enable-external-libraries

PKGCONFIG_OVERRIDE+=	xbmc-10.1/lib/enca/enca.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/lib/fribidi/fribidi.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/lib/libass/libass.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/lib/libcdio/libcdio.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/lib/libcdio/libcdio_cdda.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/lib/libcdio/libcdio_paranoia.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/lib/libcdio/libiso9660.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/lib/libmicrohttpd/libmicrohttpd.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/lib/libmodplug/libmodplug.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/lib/pcre/libpcre.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/lib/pcre/libpcreposix.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/lib/pcre/libpcrecpp.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/lib/libmms/libmms_win32/pkgconfig/libmms.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/lib/libsamplerate/samplerate.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/cores/dvdplayer/Codecs/libdts/libdts/libdts.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/cores/dvdplayer/Codecs/libdvd/libdvdcss/src/libdvdcss.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/cores/dvdplayer/Codecs/libdvd/libdvdnav/misc/dvdnavmini.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/cores/dvdplayer/Codecs/libdvd/libdvdnav/misc/dvdnav.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/cores/dvdplayer/Codecs/libdvd/libdvdread/misc/dvdread.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/cores/dvdplayer/Codecs/libmpeg2/libmpeg2/convert/libmpeg2convert.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/cores/dvdplayer/Codecs/libmpeg2/libmpeg2/libmpeg2.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/cores/paplayer/FLACCodec/flac-1.2.1/src/libFLAC++/flac++.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/cores/paplayer/FLACCodec/flac-1.2.1/src/libFLAC/flac.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/cores/paplayer/SIDCodec/libsidplay/unix/libsidplay2.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/cores/paplayer/vorbisfile/libvorbis/vorbis.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/cores/paplayer/vorbisfile/libvorbis/vorbisenc.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/cores/paplayer/vorbisfile/libvorbis/vorbisfile.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/cores/paplayer/vorbisfile/ogg/ogg.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/visualizations/Goom/goom2k4-0/libgoom2.pc.in
PKGCONFIG_OVERRIDE+=	xbmc-10.1/xbmc/visualizations/XBMCProjectM/libprojectM/libprojectM.pc.in

pre-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ./bootstrap

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libass/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../misc/libcdio/buildlink3.mk"
.include "../../net/libmms/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../net/samba35/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
