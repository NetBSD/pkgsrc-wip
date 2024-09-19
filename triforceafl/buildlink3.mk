# $NetBSD$

BUILDLINK_TREE+=	triforceafl

.if !defined(TRIFORCEAFL_BUILDLINK3_MK)
TRIFORCEAFL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.triforceafl+=	triforceafl>=0.0.2017.06.01
BUILDLINK_PKGSRCDIR.triforceafl?=	../../wip/triforceafl

.endif	# TRIFORCEAFL_BUILDLINK3_MK

BUILDLINK_TREE+=	-triforceafl
