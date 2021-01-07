# $NetBSD$

BUILDLINK_TREE+=	go-easyjson

.if !defined(GO_EASYJSON_BUILDLINK3_MK)
GO_EASYJSON_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-easyjson=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-easyjson?=		build

BUILDLINK_API_DEPENDS.go-easyjson+=	go-easyjson>=0.7.4.1
BUILDLINK_PKGSRCDIR.go-easyjson?=	../../wip/go-easyjson


.include "../../wip/go-intern/buildlink3.mk"
.endif	# GO_EASYJSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-easyjson
