# $NetBSD: Makefile,v 1.25 2021/04/21 11:42:19 adam Exp $

DISTNAME=	gst-plugins-bad-1.18.5
PKGNAME=	${DISTNAME:S/plugins/plugins1/}
CATEGORIES=	multimedia gnome
MASTER_SITES=	https://gstreamer.freedesktop.org/src/gst-plugins-bad/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gstreamer.freedesktop.org/
COMMENT=	Open source multimedia framework - bad plugins
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

USE_TOOLS+=		pkg-config perl:run

PKGCONFIG_OVERRIDE=		output/pkgconfig/*.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install

PYTHON_FOR_BUILD_ONLY=		tool

.include "options.mk"

# generated with:
# find work/gst-*/ -name *.so | sed -e "s,/[^/]*$,:," -e 's,work/[^/]*/,${WRKSRC}/,' | tr -d \\n
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/gst-libs/gst/uridownloader:${WRKSRC}/output/gst-libs/gst/adaptivedemux:${WRKSRC}/output/gst-libs/gst/audio:${WRKSRC}/output/gst-libs/gst/basecamerabinsrc:${WRKSRC}/output/gst-libs/gst/codecparsers:${WRKSRC}/output/gst-libs/gst/codecs:${WRKSRC}/output/gst-libs/gst/insertbin:${WRKSRC}/output/gst-libs/gst/interfaces:${WRKSRC}/output/gst-libs/gst/isoff:${WRKSRC}/output/gst-libs/gst/mpegts:${WRKSRC}/output/gst-libs/gst/player:${WRKSRC}/output/gst-libs/gst/sctp:${WRKSRC}/output/gst-libs/gst/transcoder:${WRKSRC}/output/gst-libs/gst/webrtc:${WRKSRC}/output/gst/accurip:${WRKSRC}/output/gst/adpcmdec:${WRKSRC}/output/gst/adpcmenc:${WRKSRC}/output/gst/aiff:${WRKSRC}/output/gst/asfmux:${WRKSRC}/output/gst/audiobuffersplit:${WRKSRC}/output/gst/audiofxbad:${WRKSRC}/output/gst/audiomixmatrix:${WRKSRC}/output/gst/audiolatency:${WRKSRC}/output/gst/audiovisualizers:${WRKSRC}/output/gst/autoconvert:${WRKSRC}/output/gst/bayer:${WRKSRC}/output/gst/camerabin2:${WRKSRC}/output/gst/coloreffects:${WRKSRC}/output/gst/debugutils:${WRKSRC}/output/gst/dvbsubenc:${WRKSRC}/output/gst/dvbsuboverlay:${WRKSRC}/output/gst/dvdspu:${WRKSRC}/output/gst/faceoverlay:${WRKSRC}/output/gst/festival:${WRKSRC}/output/gst/fieldanalysis:${WRKSRC}/output/gst/freeverb:${WRKSRC}/output/gst/frei0r:${WRKSRC}/output/gst/gaudieffects:${WRKSRC}/output/gst/gdp:${WRKSRC}/output/gst/geometrictransform:${WRKSRC}/output/gst/id3tag:${WRKSRC}/output/gst/inter:${WRKSRC}/output/gst/interlace:${WRKSRC}/output/gst/ivfparse:${WRKSRC}/output/gst/ivtc:${WRKSRC}/output/gst/jp2kdecimator:${WRKSRC}/output/gst/jpegformat:${WRKSRC}/output/gst/librfb:${WRKSRC}/output/gst/midi:${WRKSRC}/output/gst/mpegdemux:${WRKSRC}/output/gst/mpegpsmux:${WRKSRC}/output/gst/mpegtsdemux:${WRKSRC}/output/gst/mpegtsmux:${WRKSRC}/output/gst/mxf:${WRKSRC}/output/gst/netsim:${WRKSRC}/output/gst/onvif:${WRKSRC}/output/gst/pcapparse:${WRKSRC}/output/gst/pnm:${WRKSRC}/output/gst/proxy:${WRKSRC}/output/gst/rawparse:${WRKSRC}/output/gst/removesilence:${WRKSRC}/output/gst/rist:${WRKSRC}/output/gst/rtmp2:${WRKSRC}/output/gst/rtp:${WRKSRC}/output/gst/sdp:${WRKSRC}/output/gst/segmentclip:${WRKSRC}/output/gst/siren:${WRKSRC}/output/gst/smooth:${WRKSRC}/output/gst/speed:${WRKSRC}/output/gst/subenc:${WRKSRC}/output/gst/switchbin:${WRKSRC}/output/gst/timecode:${WRKSRC}/output/gst/transcode:${WRKSRC}/output/gst/videofilters:${WRKSRC}/output/gst/videoframe_audiolevel:${WRKSRC}/output/gst/videoparsers:${WRKSRC}/output/gst/videosignal:${WRKSRC}/output/gst/vmnc:${WRKSRC}/output/gst/y4m:${WRKSRC}/output/sys/ipcpipeline:${WRKSRC}/output/sys/nvcodec:${WRKSRC}/output/sys/shm:${WRKSRC}/output/ext/bz2:${WRKSRC}/output/ext/hls:

# test status as of 1.18.5
#Ok:                 47
#Expected Fail:      0
#Fail:               9
#Unexpected Pass:    0
#Skipped:            0
#Timeout:            0

# unpackaged dependencies:
# dssim
# tinyalsa

.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/openh264/buildlink3.mk"
.include "../../net/libmicrodns/buildlink3.mk"
.include "../../net/libnice/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../wip/gst-plugins1-base/buildlink3.mk"
.include "../../wip/gstreamer1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
