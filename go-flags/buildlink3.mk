# $NetBSD$

BUILDLINK_TREE+=	go-flags

.if !defined(GO_FLAGS_BUILDLINK3_MK)
GO_FLAGS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-flags=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-flags?=		build

BUILDLINK_API_DEPENDS.go-flags+=	go-flags>=1.3.0
BUILDLINK_PKGSRCDIR.go-flags?=		../../wip/go-flags
.endif	# GO_FLAGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-flags
