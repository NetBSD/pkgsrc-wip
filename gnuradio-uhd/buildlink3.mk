# $NetBSD: buildlink3.mk,v 1.1 2014/10/13 12:51:10 mef Exp $

BUILDLINK_TREE+=	gnuradio-uhd

.if !defined(GNURADIO_UHD_BUILDLINK3_MK)
GNURADIO_UHD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-uhd+=	gnuradio-uhd>=3.8.1.0
BUILDLINK_ABI_DEPENDS.gnuradio-uhd+=	gnuradio-uhd>=3.8.1.0
BUILDLINK_PKGSRCDIR.gnuradio-uhd?=	../../wip/gnuradio-uhd
.endif # GNURADIO_UHD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-uhd
