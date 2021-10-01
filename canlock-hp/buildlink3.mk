# $NetBSD$

BUILDLINK_TREE+=	canlock-hp

.if !defined(CANLOCK_HP_BUILDLINK3_MK)
CANLOCK_HP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.canlock-hp+=	canlock-hp>=3.3.0
BUILDLINK_PKGSRCDIR.canlock-hp?=	../../wip/canlock-hp
.endif	# CANLOCK_HP_BUILDLINK3_MK

BUILDLINK_TREE+=	-canlock-hp
