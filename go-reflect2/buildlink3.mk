# $NetBSD$

BUILDLINK_TREE+=	go-reflect2

.if !defined(GO_REFLECT2_BUILDLINK3_MK)
GO_REFLECT2_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-reflect2=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-reflect2?=	build

BUILDLINK_API_DEPENDS.go-reflect2+=	go-reflect2>=1.0.1
BUILDLINK_PKGSRCDIR.go-reflect2?=	../../wip/go-reflect2


.include "../../wip/go-concurrent/buildlink3.mk"
.endif	# GO_REFLECT2_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-reflect2
