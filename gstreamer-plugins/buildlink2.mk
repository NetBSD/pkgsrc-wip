# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/04/15 18:04:10 bmeurer Exp $
#
# This Makefile fragment is included by packages that use gstreamer-plugins.
#
# This file was created automatically using createbuildlink 2.4.
#

.if !defined(GSTREAMER_PLUGINS_BUILDLINK2_MK)
GSTREAMER_PLUGINS_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			gstreamer-plugins
BUILDLINK_DEPENDS.gstreamer-plugins?=		gstreamer-plugins>=0.6.0
BUILDLINK_PKGSRCDIR.gstreamer-plugins?=		../../wip/gstreamer-plugins

EVAL_PREFIX+=	BUILDLINK_PREFIX.gstreamer-plugins=gstreamer-plugins
BUILDLINK_PREFIX.gstreamer-plugins_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.gstreamer-plugins+=	include/gstreamer-0.6/gst/audio/audio.h
BUILDLINK_FILES.gstreamer-plugins+=	include/gstreamer-0.6/gst/idct/idct.h
BUILDLINK_FILES.gstreamer-plugins+=	include/gstreamer-0.6/gst/resample/resample.h
BUILDLINK_FILES.gstreamer-plugins+=	include/gstreamer-0.6/gst/riff/riff.h
BUILDLINK_FILES.gstreamer-plugins+=	include/gstreamer-0.6/gst/floatcast/floatcast.h
BUILDLINK_FILES.gstreamer-plugins+=	include/gstreamer-0.6/gst/gconf/gconf.h
BUILDLINK_FILES.gstreamer-plugins+=	include/gstreamer-0.6/gst/media-info/media-info.h
BUILDLINK_FILES.gstreamer-plugins+=	include/gstreamer-0.6/gst/play/play.h
BUILDLINK_FILES.gstreamer-plugins+=	include/gstreamer-0.6/gst/video/video.h
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgsta52dec.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstaasink.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstac3parse.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstadder.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstalaw.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstaudio.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstaudioscale.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstauparse.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstavidemux.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstavimux.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstcdxaparse.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstchart.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstcolorspace.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstcutter.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstdeinterlace.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgsteffectv.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstesdmon.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstesdsink.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstfestival.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstfilter.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstflxdec.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstgnomevfssink.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstgnomevfssrc.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstgoom.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstidct.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstintfloat.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstjpeg.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstlevel.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmad.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmedian.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmikmod.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmodplug.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmono2stereo.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmonoscope.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmp1videoparse.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmp3types.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmpeg1encoder.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmpeg1systemencode.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmpeg1types.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmpeg2enc.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmpeg2subt.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmpeg2types.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmpegaudio.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmpegaudioparse.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmpegstream.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstmulaw.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstoneton.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstpassthrough.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstplayondemand.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstqtdemux.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstresample.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstriff.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstrtjpeg.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstsdlvideosink.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstsilence.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstsinesrc.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstsmooth.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstsmpte.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstspectrum.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstspeed.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgststereo.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgststereo2mono.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgststereosplit.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstsynaesthesia.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstudp.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstvbidec.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstvideo.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstvideocrop.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstvideoscale.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstvideosink.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstvideotestsrc.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstvolenv.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstvolume.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstvorbis.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstvumeter.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstwavenc.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstwavparse.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgstxvideosink.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libgsty4menc.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/gstreamer-0.6/libmixmatrix.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/libgstgconf-0.6.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/libgstmedia-info-0.6.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/libgstplay-0.6.*
BUILDLINK_FILES.gstreamer-plugins+=	lib/pkgconfig/gstreamer-gconf-0.6.pc
BUILDLINK_FILES.gstreamer-plugins+=	lib/pkgconfig/gstreamer-libs-0.6.pc
BUILDLINK_FILES.gstreamer-plugins+=	lib/pkgconfig/gstreamer-play-0.6.pc

.include "../../audio/esound/buildlink2.mk"
.include "../../audio/liba52/buildlink2.mk"
.include "../../audio/mad/buildlink2.mk"
.include "../../audio/libmikmod/buildlink2.mk"
.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/aalib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/hermes/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../sysutils/gnome-vfs2/buildlink2.mk"
.include "../../wip/gstreamer/buildlink2.mk"

BUILDLINK_TARGETS+=	gstreamer-plugins-buildlink

gstreamer-plugins-buildlink: _BUILDLINK_USE

.endif	# GSTREAMER_PLUGINS_BUILDLINK2_MK
