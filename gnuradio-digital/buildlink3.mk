# $NetBSD: buildlink3.mk,v 1.1 2014/09/18 00:43:31 makoto Exp $

BUILDLINK_TREE+=	gnuradio-digital

.if !defined(GNURADIO_DIGITAL_BUILDLINK3_MK)
GNURADIO_DIGITAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-digital+=	gnuradio-digital>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-digital+=	gnuradio-digital>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-digital?=	../../wip/gnuradio-digital
BUILDLINK_CPPFLAGS.gnuradio-digital+=    -I${BUILDLINK_PREFIX.gnuradio-digital}/include/gnuradio
.endif # GNURADIO_DIGITAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-digital
