# $NetBSD$

BUILDLINK_TREE+=	capstone

.if !defined(CAPSTONE_BUILDLINK3_MK)
CAPSTONE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.capstone+=	capstone>=2.1.2
BUILDLINK_PKGSRCDIR.capstone?=	../../wip/frida-capstone
.endif	# CAPSTONE_BUILDLINK3_MK

BUILDLINK_TREE+=	-capstone
