# $NetBSD: buildlink3.mk,v 1.1 2014/09/18 00:43:32 makoto Exp $

BUILDLINK_TREE+=	gnuradio-fcd

.if !defined(GNURADIO_FCD_BUILDLINK3_MK)
GNURADIO_FCD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-fcd+=	gnuradio-fcd>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-fcd+=	gnuradio-fcd>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-fcd?=	../../wip/gnuradio-fcd
BUILDLINK_CPPFLAGS.gnuradio-fcd+=    -I${BUILDLINK_PREFIX.gnuradio-fcd}/include/gnuradio
.endif # GNURADIO_FCD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-fcd
