# $NetBSD$

BUILDLINK_TREE+=	go-pgzip

.if !defined(GO_PGZIP_BUILDLINK3_MK)
GO_PGZIP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-pgzip=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-pgzip?=		build

BUILDLINK_API_DEPENDS.go-pgzip+=	go-pgzip>=1.2.5
BUILDLINK_PKGSRCDIR.go-pgzip?=	../../wip/go-pgzip


.include "../../devel/go-compress/buildlink3.mk"
.endif	# GO_PGZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-pgzip
