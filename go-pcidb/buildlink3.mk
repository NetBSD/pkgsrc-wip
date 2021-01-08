# $NetBSD$

BUILDLINK_TREE+=	go-pcidb

.if !defined(GO_PCIDB_BUILDLINK3_MK)
GO_PCIDB_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-pcidb=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-pcidb?=		build

BUILDLINK_API_DEPENDS.go-pcidb+=	go-pcidb>=0.5.0
BUILDLINK_PKGSRCDIR.go-pcidb?=	../../wip/go-pcidb

.include "../../devel/go-homedir/buildlink3.mk"
.endif	# GO_PCIDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-pcidb
