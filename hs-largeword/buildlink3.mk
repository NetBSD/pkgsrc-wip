# $NetBSD: buildlink3.mk,v 1.3 2013/02/26 14:15:24 phonohawk Exp $

BUILDLINK_TREE+=	hs-largeword

.if !defined(HS_LARGEWORD_BUILDLINK3_MK)
HS_LARGEWORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-largeword+=	hs-largeword>=1.0.4
BUILDLINK_PKGSRCDIR.hs-largeword?=	../../wip/hs-largeword
.endif	# HS_LARGEWORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-largeword
