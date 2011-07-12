# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/12 07:25:01 phonohawk Exp $

BUILDLINK_TREE+=	hs-largeword

.if !defined(HS_LARGEWORD_BUILDLINK3_MK)
HS_LARGEWORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-largeword+=	hs-largeword>=1.0
BUILDLINK_PKGSRCDIR.hs-largeword?=	../../wip/hs-largeword
.endif	# HS_LARGEWORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-largeword
