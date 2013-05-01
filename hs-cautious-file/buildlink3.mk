# $NetBSD: buildlink3.mk,v 1.2 2013/05/01 12:50:32 szptvlfn Exp $

BUILDLINK_TREE+=	hs-cautious-file

.if !defined(HS_CAUTIOUS_FILE_BUILDLINK3_MK)
HS_CAUTIOUS_FILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cautious-file+=	hs-cautious-file>=1.0.2
BUILDLINK_PKGSRCDIR.hs-cautious-file?=	../../wip/hs-cautious-file
.endif	# HS_CAUTIOUS_FILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cautious-file
