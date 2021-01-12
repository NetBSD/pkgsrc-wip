# $NetBSD$

BUILDLINK_TREE+=	go-gorilla-schema

.if !defined(GO_GORILLA_SCHEMA_BUILDLINK3_MK)
GO_GORILLA_SCHEMA_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-gorilla-schema=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-gorilla-schema?=		build

BUILDLINK_API_DEPENDS.go-gorilla-schema+=	go-gorilla-schema>=1.2.0
BUILDLINK_PKGSRCDIR.go-gorilla-schema?=		../../wip/go-gorilla-schema
.endif	# GO_GORILLA_SCHEMA_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-gorilla-schema
