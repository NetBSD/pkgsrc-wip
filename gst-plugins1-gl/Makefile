# $NetBSD: Makefile,v 1.5 2021/11/17 08:36:03 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-gl/}
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - GL plugin

# this doesn't work
#GST_EXT_BUILD=	# defined
GST_PLUGINS+=	drm gl

# so we need to delete stuff manually

post-install:
	cd ${DESTDIR}${PREFIX} && \
		${RM} -rf \
			include/gstreamer-1.0/gst/allocators \
			include/gstreamer-1.0/gst/app \
			include/gstreamer-1.0/gst/audio \
			include/gstreamer-1.0/gst/fft \
			include/gstreamer-1.0/gst/pbutils \
			include/gstreamer-1.0/gst/riff \
			include/gstreamer-1.0/gst/rtp \
			include/gstreamer-1.0/gst/rtsp \
			include/gstreamer-1.0/gst/sdp \
			include/gstreamer-1.0/gst/tag \
			include/gstreamer-1.0/gst/video \
			include/gstreamer-1.0/gst/video \
			lib/libgstallocators-1.0.so* \
			lib/libgstapp-1.0.so* \
			lib/libgstaudio-1.0.so* \
			lib/libgstfft-1.0.so* \
			lib/libgstpbutils-1.0.so* \
			lib/libgstriff-1.0.so* \
			lib/libgstrtp-1.0.so* \
			lib/libgstrtsp-1.0.so* \
			lib/libgstsdp-1.0.so* \
			lib/libgsttag-1.0.so* \
			lib/libgstvideo-1.0.so* \
			lib/pkgconfig/gstreamer-allocators-1.0.pc \
			lib/pkgconfig/gstreamer-app-1.0.pc \
			lib/pkgconfig/gstreamer-audio-1.0.pc \
			lib/pkgconfig/gstreamer-fft-1.0.pc \
			lib/pkgconfig/gstreamer-pbutils-1.0.pc \
			lib/pkgconfig/gstreamer-plugins-base-1.0.pc \
			lib/pkgconfig/gstreamer-riff-1.0.pc \
			lib/pkgconfig/gstreamer-rtp-1.0.pc \
			lib/pkgconfig/gstreamer-rtsp-1.0.pc \
			lib/pkgconfig/gstreamer-sdp-1.0.pc \
			lib/pkgconfig/gstreamer-tag-1.0.pc \
			lib/pkgconfig/gstreamer-video-1.0.pc \
			share/gst-plugins-base/1.0/license-translations.dict

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
