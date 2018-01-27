# $NetBSD: buildlink3.mk,v 1.3 2014/09/29 15:25:54 makoto Exp $

BUILDLINK_TREE+=	gnuradio-default

.if !defined(GNURADIO_DEFAULT_BUILDLINK3_MK)
GNURADIO_DEFAULT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-default+=	gnuradio-default>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-default+=	gnuradio-default>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-default?=		../../wip/gnuradio-default
.endif # GNURADIO_DEFAULT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-default
