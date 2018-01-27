# $NetBSD: buildlink3.mk,v 1.3 2015/09/17 13:48:06 makoto Exp $

BUILDLINK_TREE+=	gnuradio-vocoder

.if !defined(GNURADIO_VOCODER_BUILDLINK3_MK)
GNURADIO_VOCODER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-vocoder+=	gnuradio-vocoder>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-vocoder+=	gnuradio-vocoder>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-vocoder?=		../../wip/gnuradio-vocoder
.endif # GNURADIO_VOCODER_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-vocoder
