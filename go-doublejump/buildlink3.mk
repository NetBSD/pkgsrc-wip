# $NetBSD$

BUILDLINK_TREE+=	go-doublejump

.if !defined(GO_DOUBLEJUMP_BUILDLINK3_MK)
GO_DOUBLEJUMP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-doublejump=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-doublejump?=		build

BUILDLINK_API_DEPENDS.go-doublejump+=	go-doublejump>=20200330
BUILDLINK_PKGSRCDIR.go-doublejump?=	../../wip/go-doublejump

.include "../../wip/go-jump/buildlink3.mk"
.endif	# GO_DOUBLEJUMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-doublejump
