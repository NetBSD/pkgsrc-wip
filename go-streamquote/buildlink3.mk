# $NetBSD$

BUILDLINK_TREE+=	go-streamquote

.if !defined(GO_STREAMQUOTE_BUILDLINK3_MK)
GO_STREAMQUOTE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-streamquote=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-streamquote?=		build

BUILDLINK_API_DEPENDS.go-streamquote+=	go-streamquote>=1.0.0
BUILDLINK_PKGSRCDIR.go-streamquote?=	../../wip/go-streamquote
.endif	# GO_STREAMQUOTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-streamquote
