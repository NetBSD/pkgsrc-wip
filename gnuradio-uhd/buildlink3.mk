# $NetBSD: buildlink3.mk,v 1.1 2014/09/18 00:43:32 makoto Exp $

BUILDLINK_TREE+=	gnuradio-uhd

.if !defined(GNURADIO_UHD_BUILDLINK3_MK)
GNURADIO_UHD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnuradio-uhd+=	gnuradio-uhd>=3.7.5
BUILDLINK_ABI_DEPENDS.gnuradio-uhd+=	gnuradio-uhd>=3.7.5
BUILDLINK_PKGSRCDIR.gnuradio-uhd?=	../../wip/gnuradio-uhd
BUILDLINK_CPPFLAGS.gnuradio-uhd+=    -I${BUILDLINK_PREFIX.gnuradio-uhd}/include/gnuradio
.endif # GNURADIO_UHD_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnuradio-uhd
