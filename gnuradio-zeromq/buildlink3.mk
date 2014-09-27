# $NetBSD: buildlink3.mk,v 1.1 2014/09/27 17:07:39 makoto Exp $

BUILDLINK_TREE+=	gnuradio-zeromq

.if !defined(GNURADIO_ZEROMQ_BUILDLINK3_MK)
GNURADIO_ZEROMQ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-zeromq+=	gnuradio-zeromq>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-zeromq+=	gnuradio-zeromq>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-zeromq?=	../../wip/gnuradio-zeromq
BUILDLINK_CPPFLAGS.gnuradio-zeromq+=    -I${BUILDLINK_PREFIX.gnuradio-zeromq}/include/gnuradio
.endif # GNURADIO_ZEROMQ_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-zeromq
