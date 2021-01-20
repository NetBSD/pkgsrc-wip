# $NetBSD$

BUILDLINK_TREE+=	go-json-iterator

.if !defined(GO_JSON_ITERATOR_BUILDLINK3_MK)
GO_JSON_ITERATOR_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-json-iterator=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-json-iterator?=		build

BUILDLINK_API_DEPENDS.go-json-iterator+=	go-json-iterator>=20200608
BUILDLINK_PKGSRCDIR.go-json-iterator?=		../../wip/go-json-iterator


.include "../../wip/go-concurrent/buildlink3.mk"
.include "../../wip/go-reflect2/buildlink3.mk"
.endif	# GO_JSON_ITERATOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-json-iterator
