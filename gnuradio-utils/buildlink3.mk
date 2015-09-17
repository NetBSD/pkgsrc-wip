# $NetBSD: buildlink3.mk,v 1.3 2015/09/17 13:48:06 makoto Exp $

BUILDLINK_TREE+=	gnuradio-utils

.if !defined(GNURADIO_UTILS_BUILDLINK3_MK)
GNURADIO_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-utils+=	gnuradio-utils>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-utils+=	gnuradio-utils>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-utils?=	../../wip/gnuradio-utils
.endif # GNURADIO_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-utils
