# $NetBSD$

BUILDLINK_TREE+=	frida-capstone

.if !defined(FRIDA_CAPSTONE_BUILDLINK3_MK)
FRIDA_CAPSTONE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.frida-capstone+=	frida-capstone>=2.1.2
BUILDLINK_PKGSRCDIR.frida-capstone?=	../../wip/frida-capstone
.endif	# FRIDA_CAPSTONE_BUILDLINK3_MK

BUILDLINK_TREE+=	-frida-capstone
