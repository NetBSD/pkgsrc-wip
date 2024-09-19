# $NetBSD$

BUILDLINK_TREE+=	go-bindata-assetfs

.if !defined(GO_BINDATA_ASSETFS_BUILDLINK3_MK)
GO_BINDATA_ASSETFS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-bindata-assetfs=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-bindata-assetfs?=		build

BUILDLINK_API_DEPENDS.go-bindata-assetfs+=	go-bindata-assetfs>=20201223nb1
BUILDLINK_PKGSRCDIR.go-bindata-assetfs?=	../../wip/go-bindata-assetfs
.endif	# GO_BINDATA_ASSETFS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-bindata-assetfs
