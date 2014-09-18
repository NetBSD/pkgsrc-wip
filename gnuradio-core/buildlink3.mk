# $NetBSD: buildlink3.mk,v 1.3 2014/09/18 00:43:30 makoto Exp $

BUILDLINK_TREE+=	gnuradio-core

.if !defined(GNURADIO_CORE_BUILDLINK3_MK)
GNURADIO_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-core+=	gnuradio-core>=3.0.4
BUILDLINK_ABI_DEPENDS.gnuradio-core+=	gnuradio-core>=3.3.0nb10
BUILDLINK_PKGSRCDIR.gnuradio-core?=	../../wip/gnuradio-core
BUILDLINK_CPPFLAGS.gnuradio-core+=    -I${BUILDLINK_PREFIX.gnuradio-core}/include/gnuradio
.endif # GNURADIO_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-core
