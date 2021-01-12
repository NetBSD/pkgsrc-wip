# $NetBSD$

BUILDLINK_TREE+=	go-redigo

.if !defined(GO_REDIGO_BUILDLINK3_MK)
GO_REDIGO_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-redigo=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-redigo?=		build

BUILDLINK_API_DEPENDS.go-redigo+=	go-redigo>=1.8.3
BUILDLINK_PKGSRCDIR.go-redigo?=		../../wip/go-redigo
.endif	# GO_REDIGO_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-redigo
