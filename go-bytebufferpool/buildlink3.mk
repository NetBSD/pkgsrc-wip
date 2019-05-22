# $NetBSD$

BUILDLINK_TREE+=	go-bytebufferpool

.if !defined(GO_BYTEBUFFERPOOL_BUILDLINK3_MK)
GO_BYTEBUFFERPOOL_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-bytebufferpool=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-bytebufferpool?=		build

BUILDLINK_API_DEPENDS.go-bytebufferpool+=	go-bytebufferpool>=1.0.0
BUILDLINK_PKGSRCDIR.go-bytebufferpool?=		../../wip/go-bytebufferpool
.endif	# GO_BYTEBUFFERPOOL_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-bytebufferpool
