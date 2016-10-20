# $NetBSD$

BUILDLINK_TREE+=	threadingbuildingblocks

.if !defined(THREADINGBUILDINGBLOCKS_BUILDLINK3_MK)
THREADINGBUILDINGBLOCKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.threadingbuildingblocks+=	threadingbuildingblocks>=2017.20160916
BUILDLINK_PKGSRCDIR.threadingbuildingblocks?=	../../wip/threadingbuildingblocks
.endif	# THREADINGBUILDINGBLOCKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-threadingbuildingblocks
