# $NetBSD$

BUILDLINK_TREE+=	cinnamon-session

.if !defined(CINNAMON_SESSION_BUILDLINK3_MK)
CINNAMON_SESSION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cinnamon-session+=	cinnamon-session>=3.8.1
BUILDLINK_PKGSRCDIR.cinnamon-session?=		../../wip/cinnamon-session

.endif	# CINNAMON_SESSION_BUILDLINK3_MK

BUILDLINK_TREE+=	-cinnamon-session
