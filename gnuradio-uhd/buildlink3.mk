# $NetBSD: buildlink3.mk,v 1.3 2015/09/17 13:48:06 makoto Exp $

BUILDLINK_TREE+=	gnuradio-uhd

.if !defined(GNURADIO_UHD_BUILDLINK3_MK)
GNURADIO_UHD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-uhd+=	gnuradio-uhd>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-uhd+=	gnuradio-uhd>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-uhd?=	../../wip/gnuradio-uhd
.endif # GNURADIO_UHD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-uhd
