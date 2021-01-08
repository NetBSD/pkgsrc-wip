# $NetBSD$

BUILDLINK_TREE+=	go-raymond

.if !defined(GO_RAYMOND_BUILDLINK3_MK)
GO_RAYMOND_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-raymond=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-raymond?=	build

BUILDLINK_API_DEPENDS.go-raymond+=	go-raymond>=2.0.2
BUILDLINK_PKGSRCDIR.go-raymond?=	../../wip/go-raymond
.endif	# GO_RAYMOND_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-raymond
