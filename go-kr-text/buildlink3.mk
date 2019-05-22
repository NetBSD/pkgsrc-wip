# $NetBSD$

BUILDLINK_TREE+=	go-kr-text

.if !defined(GO_KR_TEXT_BUILDLINK3_MK)
GO_KR_TEXT_BUILDLINK3_MK=

BUILDLINK_CONTENTS_FILTER.go-kr-text=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-kr-text?=	build

BUILDLINK_API_DEPENDS.go-kr-text+=		go-kr-text>=0.0
BUILDLINK_PKGSRCDIR.go-kr-text?=		../../wip/go-kr-text
.endif  # GO_KR_TEXT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-kr-text
