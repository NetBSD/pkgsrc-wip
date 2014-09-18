# $NetBSD: buildlink3.mk,v 1.1 2014/09/18 00:43:32 makoto Exp $

BUILDLINK_TREE+=	gnuradio-fec

.if !defined(GNURADIO_FEC_BUILDLINK3_MK)
GNURADIO_FEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-fec+=	gnuradio-fec>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-fec+=	gnuradio-fec>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-fec?=	../../wip/gnuradio-fec
BUILDLINK_CPPFLAGS.gnuradio-fec+=    -I${BUILDLINK_PREFIX.gnuradio-fec}/include/gnuradio
.endif # GNURADIO_FEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-fec
