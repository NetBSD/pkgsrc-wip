# $NetBSD$

BUILDLINK_TREE+=	go-securecookie

.if !defined(GO_SECURECOOKIE_BUILDLINK3_MK)
GO_SECURECOOKIE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-securecookie=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-securecookie?=		build

BUILDLINK_API_DEPENDS.go-securecookie+=	go-securecookie>=1.1.1
BUILDLINK_PKGSRCDIR.go-securecookie?=	../../wip/go-gorilla-securecookie
.endif	# GO_SECURECOOKIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-securecookie
