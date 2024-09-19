# $NetBSD: buildlink3.mk,v 1.4 2014/08/29 14:10:25 szptvlfn Exp $

BUILDLINK_TREE+=	hs-largeword

.if !defined(HS_LARGEWORD_BUILDLINK3_MK)
HS_LARGEWORD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-largeword+=	hs-largeword>=1.0.4
BUILDLINK_ABI_DEPENDS.hs-largeword+=	hs-largeword>=1.0.4
BUILDLINK_PKGSRCDIR.hs-largeword?=	../../wip/hs-largeword
.endif	# HS_LARGEWORD_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-largeword
