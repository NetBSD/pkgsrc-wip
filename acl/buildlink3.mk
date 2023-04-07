# $NetBSD$

BUILDLINK_TREE+=	acl

.if !defined(ACL_BUILDLINK3_MK)
ACL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.acl+=	acl>=2.2.52
BUILDLINK_PKGSRCDIR.acl?=	../../devel/acl

.include "../../sysutils/attr/buildlink3.mk"
.endif	# ACL_BUILDLINK3_MK

BUILDLINK_TREE+=	-acl
