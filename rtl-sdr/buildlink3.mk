# $NetBSD: buildlink3.mk,v 1.1 2014/09/09 23:10:22 makoto Exp $

BUILDLINK_TREE+=	rtl-sdr

.if !defined(RTL_SDR_BUILDLINK3_MK)
RTL_SDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rtl-sdr+=	rtl-sdr>=0.5.3
BUILDLINK_ABI_DEPENDS.rtl-sdr+=	rtl-sdr>=0.5.3
BUILDLINK_PKGSRCDIR.rtl-sdr?=	../../wip/rtl-sdr

.endif # RTL_SDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-rtl-sdr
