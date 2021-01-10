# $NetBSD$

BUILDLINK_TREE+=	go-httpsnoop

.if !defined(GO_HTTPSNOOP_BUILDLINK3_MK)
GO_HTTPSNOOP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-httpsnoop=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-httpsnoop?=	build

BUILDLINK_API_DEPENDS.go-httpsnoop+=	go-httpsnoop>=20200910
BUILDLINK_PKGSRCDIR.go-httpsnoop?=	../../wip/go-httpsnoop
.endif	# GO_HTTPSNOOP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-httpsnoop
