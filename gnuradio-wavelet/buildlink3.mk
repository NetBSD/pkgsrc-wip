# $NetBSD: buildlink3.mk,v 1.1 2014/09/18 00:43:32 makoto Exp $

BUILDLINK_TREE+=	gnuradio-wavelet

.if !defined(GNURADIO_WAVELET_BUILDLINK3_MK)
GNURADIO_WAVELET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-wavelet+=	gnuradio-wavelet>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-wavelet+=	gnuradio-wavelet>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-wavelet?=	../../wip/gnuradio-wavelet
BUILDLINK_CPPFLAGS.gnuradio-wavelet+=    -I${BUILDLINK_PREFIX.gnuradio-wavelet}/include/gnuradio
.endif # GNURADIO_WAVELET_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-wavelet
