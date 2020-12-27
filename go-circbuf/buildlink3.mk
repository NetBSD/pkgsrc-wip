# $NetBSD$

BUILDLINK_TREE+=	go-circbuf

.if !defined(GO_CIRCBUF_BUILDLINK3_MK)
GO_CIRCBUF_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-circbuf=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-circbuf?=		build

BUILDLINK_API_DEPENDS.go-circbuf+=	go-circbuf>=0.0.14022019
BUILDLINK_PKGSRCDIR.go-circbuf?=	../../wip/go-circbuf
.endif	# GO_CIRCBUF_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-circbuf
