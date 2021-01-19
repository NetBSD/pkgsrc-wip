# $NetBSD$

BUILDLINK_TREE+=	go-curlie

.if !defined(GO_CURLIE_BUILDLINK3_MK)
GO_CURLIE_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-curlie=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-curlie?=		build

BUILDLINK_API_DEPENDS.go-curlie+=	go-curlie>=1.6.0
BUILDLINK_PKGSRCDIR.go-curlie?=		../../category/go-curlie

.include "../../security/go-crypto/buildlink3.mk"
.endif	# GO_CURLIE_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-curlie
