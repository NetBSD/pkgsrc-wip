# $NetBSD$

BUILDLINK_TREE+=	threadingbuildingblocks

.if !defined(THREADINGBUILDINGBLOCKS_BUILDLINK3_MK)
THREADINGBUILDINGBLOCKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.threadingbuildingblocks+=	threadingbuildingblocks>=2018.5
BUILDLINK_PKGSRCDIR.threadingbuildingblocks?=	../../wip/threadingbuildingblocks
.endif	# THREADINGBUILDINGBLOCKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-threadingbuildingblocks
