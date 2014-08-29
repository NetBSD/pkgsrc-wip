# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:28 szptvlfn Exp $

BUILDLINK_TREE+=	hs-system-filepath

.if !defined(HS_SYSTEM_FILEPATH_BUILDLINK3_MK)
HS_SYSTEM_FILEPATH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-system-filepath+=	hs-system-filepath>=0.4.7
BUILDLINK_ABI_DEPENDS.hs-system-filepath+=	hs-system-filepath>=0.4.7
BUILDLINK_PKGSRCDIR.hs-system-filepath?=	../../wip/hs-system-filepath

.endif	# HS_SYSTEM_FILEPATH_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-system-filepath
