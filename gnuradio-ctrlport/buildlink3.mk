# $NetBSD: buildlink3.mk,v 1.1 2014/10/13 12:51:08 mef Exp $

BUILDLINK_TREE+=	gnuradio-ctrlport

.if !defined(GNURADIO_CTRLPORT_BUILDLINK3_MK)
GNURADIO_CTRLPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-ctrlport+=	gnuradio-ctrlport>=3.8.1.0
BUILDLINK_ABI_DEPENDS.gnuradio-ctrlport+=	gnuradio-ctrlport>=3.8.1.0
BUILDLINK_PKGSRCDIR.gnuradio-ctrlport?=		../../wip/gnuradio-ctrlport
.endif # GNURADIO_CTRLPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-ctrlport
