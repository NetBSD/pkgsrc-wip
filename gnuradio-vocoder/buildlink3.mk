# $NetBSD: buildlink3.mk,v 1.1 2014/09/18 00:43:32 makoto Exp $

BUILDLINK_TREE+=	gnuradio-vocoder

.if !defined(GNURADIO_VOCODER_BUILDLINK3_MK)
GNURADIO_VOCODER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-vocoder+=	gnuradio-vocoder>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-vocoder+=	gnuradio-vocoder>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-vocoder?=	../../wip/gnuradio-vocoder
BUILDLINK_CPPFLAGS.gnuradio-vocoder+=    -I${BUILDLINK_PREFIX.gnuradio-vocoder}/include/gnuradio
.endif # GNURADIO_VOCODER_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-vocoder
