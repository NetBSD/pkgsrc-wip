# $NetBSD$

BUILDLINK_TREE+=	rtl-sdr

.if !defined(RTL_SDR_BUILDLINK3_MK)
RTL_SDR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rtl-sdr+=	rtl-sdr>=0.5nb20150922
BUILDLINK_PKGSRCDIR.rtl-sdr?=	../../wip/rtl-sdr-git

.endif	# RTL_SDR_BUILDLINK3_MK

BUILDLINK_TREE+=	-rtl-sdr
