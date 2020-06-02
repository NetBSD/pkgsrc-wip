# $NetBSD$

BUILDLINK_TREE+=	openzwave

.if !defined(OPENZWAVE_BUILDLINK3_MK)
OPENZWAVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openzwave+=	openzwave>=1.6.1123
BUILDLINK_PKGSRCDIR.openzwave?=	../../wip/openzwave

.endif	# OPENZWAVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-openzwave
