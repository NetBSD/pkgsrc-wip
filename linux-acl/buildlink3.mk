# $NetBSD$

BUILDLINK_TREE+=	linux-acl

.if !defined(LINUX_ACL_BUILDLINK3_MK)
LINUX_ACL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.linux-acl+=	linux-acl>=2.2.52
BUILDLINK_PKGSRCDIR.linux-acl?=	../../wip/linux-acl

.include "../../wip/linux-attr/buildlink3.mk"
.endif	# LINUX_ACL_BUILDLINK3_MK

BUILDLINK_TREE+=	-linux-acl
