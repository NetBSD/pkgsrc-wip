# $NetBSD$

BUILDLINK_TREE+=	go-protobuf-go

.if !defined(GO_PROTOBUF_GO_BUILDLINK3_MK)
GO_PROTOBUF_GO_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-protobuf-go=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-protobuf-go?=		build

BUILDLINK_API_DEPENDS.go-protobuf-go+=	go-protobuf-go>=1.22.0
BUILDLINK_PKGSRCDIR.go-protobuf-go?=	../../wip/go-protobuf-go
.endif	# GO_PROTOBUF_GO_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-protobuf-go
