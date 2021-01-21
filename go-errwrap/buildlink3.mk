# $NetBSD$

BUILDLINK_TREE+=	go-errwrap

.if !defined(GO_ERRWRAP_BUILDLINK3_MK)
GO_ERRWRAP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-errwrap=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-errwrap?=	build

BUILDLINK_API_DEPENDS.go-errwrap+=	go-errwrap>=1.1.0
BUILDLINK_PKGSRCDIR.go-errwrap?=	../../wip/go-errwrap
.endif	# GO_ERRWRAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-errwrap
