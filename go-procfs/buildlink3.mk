# $NetBSD$

BUILDLINK_TREE+=	go-procfs

.if !defined(GO_PROCFS_BUILDLINK3_MK)
GO_PROCFS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-procfs=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-procfs?=		build

BUILDLINK_API_DEPENDS.go-procfs+=	go-procfs>=0.3.0
BUILDLINK_PKGSRCDIR.go-procfs?=		../../wip/go-procfs

.include "../../devel/go-sync/buildlink3.mk"
.include "../../devel/go-sys/buildlink3.mk"
.endif	# GO_PROCFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-procfs
