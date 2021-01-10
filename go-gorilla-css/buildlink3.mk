# $NetBSD$

BUILDLINK_TREE+=	go-gorilla-css

.if !defined(GO_GORILLA_CSS_BUILDLINK3_MK)
GO_GORILLA_CSS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-gorilla-css=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-gorilla-css?=		build

BUILDLINK_API_DEPENDS.go-gorilla-css+=	go-gorilla-css>=20190627
BUILDLINK_PKGSRCDIR.go-gorilla-css?=	../../wip/go-gorilla-css
.endif	# GO_GORILLA_CSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-gorilla-css
