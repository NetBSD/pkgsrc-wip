# $NetBSD$

BUILDLINK_TREE+=	go-gorilla-mux

.if !defined(GO_GORILLA_MUX_BUILDLINK3_MK)
GO_GORILLA_MUX_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-gorilla-mux=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-gorilla-mux?=		build

BUILDLINK_API_DEPENDS.go-gorilla-mux+=	go-gorilla-mux>=1.8.0
BUILDLINK_PKGSRCDIR.go-gorilla-mux?=	../../wip/go-gorilla-mux
.endif	# GO_GORILLA_MUX_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-gorilla-mux
