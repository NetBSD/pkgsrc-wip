# $NetBSD$

BUILDLINK_TREE+=	go-uuid

.if !defined(GO_UUID_BUILDLINK3_MK)
GO_UUID_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-uuid=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-uuid?=		build

BUILDLINK_API_DEPENDS.go-uuid+=	go-uuid>=1.1.3
BUILDLINK_PKGSRCDIR.go-uuid?=	../../wip/go-uuid


.include "../../devel/go-sync/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.endif	# GO_UUID_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-uuid
