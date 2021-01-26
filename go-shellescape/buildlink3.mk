# $NetBSD$

BUILDLINK_TREE+=	go-shellescape

.if !defined(GO_SHELLESCAPE_BUILDLINK3_MK)
GO_SHELLESCAPE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-shellescape=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-shellescape?=		build

BUILDLINK_API_DEPENDS.go-shellescape+=	go-shellescape>=1.4.1
BUILDLINK_PKGSRCDIR.go-shellescape?=	../../wip/go-shellescape
.endif	# GO_SHELLESCAPE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-shellescape
