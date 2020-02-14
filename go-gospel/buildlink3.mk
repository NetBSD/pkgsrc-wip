# $NetBSD$

BUILDLINK_TREE+=	go-gospel

.if !defined(GO_GOSPEL_BUILDLINK3_MK)
GO_GOSPEL_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-gospel=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-gospel?=		build

BUILDLINK_API_DEPENDS.go-gospel+=	go-gospel>=0.0.20190922
BUILDLINK_PKGSRCDIR.go-gospel?=		../../wip/go-gospel

.include "../../security/go-crypto/buildlink3.mk"
.include "../../textproc/go-text/buildlink3.mk"
.endif  # GO_GOSPEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-gospel
