# $NetBSD: buildlink3.mk,v 1.2 2014/09/18 03:43:28 makoto Exp $

BUILDLINK_TREE+=	gnuradio-default

.if !defined(GNURADIO_DEFAULT_BUILDLINK3_MK)
GNURADIO_DEFAULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-default+=	gnuradio-default>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-default+=	gnuradio-default>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-default?=	../../wip/gnuradio-default
BUILDLINK_CPPFLAGS.gnuradio-default+=    -I${BUILDLINK_PREFIX.gnuradio-default}/include/gnuradio
.endif # GNURADIO_DEFAULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-default
