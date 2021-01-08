# $NetBSD$

BUILDLINK_TREE+=	go-goreferrer

.if !defined(GO_GOREFERRER_BUILDLINK3_MK)
GO_GOREFERRER_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-goreferrer=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-goreferrer?=		build

BUILDLINK_API_DEPENDS.go-goreferrer+=	go-goreferrer>=20181106
BUILDLINK_PKGSRCDIR.go-goreferrer?=	../../wip/go-goreferrer

.include "../../net/go-net/buildlink3.mk"
.endif	# GO_GOREFERRER_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-goreferrer
