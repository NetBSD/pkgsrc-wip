# $NetBSD: buildlink3.mk,v 1.1 2014/09/18 00:43:32 makoto Exp $

BUILDLINK_TREE+=	gnuradio-utils

.if !defined(GNURADIO_UTILS_BUILDLINK3_MK)
GNURADIO_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-utils+=	gnuradio-utils>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-utils+=	gnuradio-utils>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-utils?=	../../wip/gnuradio-utils
BUILDLINK_CPPFLAGS.gnuradio-utils+=    -I${BUILDLINK_PREFIX.gnuradio-utils}/include/gnuradio
.endif # GNURADIO_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-utils
