# $NetBSD: buildlink3.mk,v 1.1 2014/09/18 00:43:31 makoto Exp $

BUILDLINK_TREE+=	gnuradio-default

.if !defined(GNURADIO_DEFAULT_BUILDLINK3_MK)
GNURADIO_DEFAULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-default+=	gnuradio-default>=3.0.4
BUILDLINK_ABI_DEPENDS.gnuradio-default+=	gnuradio-default>=3.3.0nb10
BUILDLINK_PKGSRCDIR.gnuradio-default?=	../../wip/gnuradio-default
BUILDLINK_CPPFLAGS.gnuradio-default+=    -I${BUILDLINK_PREFIX.gnuradio-default}/include/gnuradio
.endif # GNURADIO_DEFAULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-default
