# $NetBSD: buildlink3.mk,v 1.3 2014/08/29 14:10:09 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cautious-file

.if !defined(HS_CAUTIOUS_FILE_BUILDLINK3_MK)
HS_CAUTIOUS_FILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cautious-file+=	hs-cautious-file>=1.0.2
BUILDLINK_ABI_DEPENDS.hs-cautious-file+=	hs-cautious-file>=1.0.2
BUILDLINK_PKGSRCDIR.hs-cautious-file?=		../../wip/hs-cautious-file
.endif	# HS_CAUTIOUS_FILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cautious-file
