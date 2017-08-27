# $NetBSD$

BUILDLINK_TREE+=	go-pass

.if !defined(GO_PASS_BUILDLINK3_MK)
GO_PASS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-pass=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-pass?=		build

BUILDLINK_API_DEPENDS.go-pass+=	go-pass>=0.0.1
BUILDLINK_PKGSRCDIR.go-pass?=	../../wip/go-pass
.endif	# GO_PASS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-pass
