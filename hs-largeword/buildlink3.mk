# $NetBSD: buildlink3.mk,v 1.2 2012/03/04 08:02:28 phonohawk Exp $

BUILDLINK_TREE+=	hs-largeword

.if !defined(HS_LARGEWORD_BUILDLINK3_MK)
HS_LARGEWORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-largeword+=	hs-largeword>=1.0.1
BUILDLINK_PKGSRCDIR.hs-largeword?=	../../wip/hs-largeword
.endif	# HS_LARGEWORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-largeword
