# $NetBSD$

BUILDLINK_TREE+=	orocos-kdl

.if !defined(OROCOS_KDL_BUILDLINK3_MK)
OROCOS_KDL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.orocos-kdl+=	orocos-kdl>=1.3.1
BUILDLINK_ABI_DEPENDS.orocos-kdl+=	orocos-kdl>=1.3.1
BUILDLINK_PKGSRCDIR.orocos-kdl?=	../../wip/orocos-kdl
.endif # OROCOS_KDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-orocos-kdl
