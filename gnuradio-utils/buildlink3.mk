# $NetBSD: buildlink3.mk,v 1.1 2014/10/13 12:51:10 mef Exp $

BUILDLINK_TREE+=	gnuradio-utils

.if !defined(GNURADIO_UTILS_BUILDLINK3_MK)
GNURADIO_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-utils+=	gnuradio-utils>=3.8.1.0
BUILDLINK_ABI_DEPENDS.gnuradio-utils+=	gnuradio-utils>=3.8.1.0
BUILDLINK_PKGSRCDIR.gnuradio-utils?=	../../wip/gnuradio-utils
.endif # GNURADIO_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-utils
