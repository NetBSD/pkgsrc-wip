# $NetBSD: buildlink3.mk,v 1.2 2014/08/29 14:10:27 szptvlfn Exp $

BUILDLINK_TREE+=	hs-numeric-quest

.if !defined(HS_NUMERIC_QUEST_BUILDLINK3_MK)
HS_NUMERIC_QUEST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-numeric-quest+=	hs-numeric-quest>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-numeric-quest+=	hs-numeric-quest>=0.1.1
BUILDLINK_PKGSRCDIR.hs-numeric-quest?=		../../wip/hs-numeric-quest
.endif	# HS_NUMERIC_QUEST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-numeric-quest
