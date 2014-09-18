# $NetBSD: buildlink3.mk,v 1.1 2014/09/18 00:43:32 makoto Exp $

BUILDLINK_TREE+=	gnuradio-trellis

.if !defined(GNURADIO_TRELLIS_BUILDLINK3_MK)
GNURADIO_TRELLIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-trellis+=	gnuradio-trellis>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-trellis+=	gnuradio-trellis>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-trellis?=	../../wip/gnuradio-trellis
BUILDLINK_CPPFLAGS.gnuradio-trellis+=    -I${BUILDLINK_PREFIX.gnuradio-trellis}/include/gnuradio
.endif # GNURADIO_TRELLIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-trellis
