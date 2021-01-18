# $NetBSD$

BUILDLINK_TREE+=	go-astikit

.if !defined(GO_ASTIKIT_BUILDLINK3_MK)
GO_ASTIKIT_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-astikit=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-astikit?=		build

BUILDLINK_API_DEPENDS.go-astikit+=	go-astikit>=0.15.0
BUILDLINK_PKGSRCDIR.go-astikit?=	../../wip/go-astikit
.endif	# GO_ASTIKIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-astikit
