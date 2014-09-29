# $NetBSD: buildlink3.mk,v 1.2 2014/09/29 15:25:54 makoto Exp $

BUILDLINK_TREE+=	gnuradio-trellis

.if !defined(GNURADIO_TRELLIS_BUILDLINK3_MK)
GNURADIO_TRELLIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-trellis+=	gnuradio-trellis>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-trellis+=	gnuradio-trellis>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-trellis?=	../../wip/gnuradio-trellis
.endif # GNURADIO_TRELLIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-trellis
