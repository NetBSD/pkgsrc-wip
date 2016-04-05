# $NetBSD$

BUILDLINK_TREE+=	lxappearance

.if !defined(LXAPPEARANCE_BUILDLINK3_MK)
LXAPPEARANCE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lxappearance+=	lxappearance>=0.6.2
BUILDLINK_PKGSRCDIR.lxappearance?=	../../wip/lxappearance

.endif	# LXAPPEARANCE_BUILDLINK3_MK

BUILDLINK_TREE+=	-lxappearance
