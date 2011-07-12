# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/12 15:19:24 phonohawk Exp $

BUILDLINK_TREE+=	hs-cautious-file

.if !defined(HS_CAUTIOUS_FILE_BUILDLINK3_MK)
HS_CAUTIOUS_FILE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-cautious-file+=	hs-cautious-file>=1.0
BUILDLINK_PKGSRCDIR.hs-cautious-file?=	../../wip/hs-cautious-file
.endif	# HS_CAUTIOUS_FILE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-cautious-file
