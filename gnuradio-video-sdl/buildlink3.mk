# $NetBSD: buildlink3.mk,v 1.3 2015/09/17 13:48:06 makoto Exp $

BUILDLINK_TREE+=	gnuradio-video-sdl

.if !defined(GNURADIO_VIDEO_SDL_BUILDLINK3_MK)
GNURADIO_VIDEO_SDL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-video-sdl+=	gnuradio-video-sdl>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-video-sdl+=	gnuradio-video-sdl>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-video-sdl?=	../../wip/gnuradio-video-sdl
.endif # GNURADIO_VIDEO_SDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-video-sdl
