# $NetBSD$

BUILDLINK_TREE+=	go-ops

.if !defined(GO_OPS_BUILDLINK3_MK)
GO_OPS_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-ops=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-ops?=		build

BUILDLINK_API_DEPENDS.go-ops+=	go-ops>=20200503
BUILDLINK_PKGSRCDIR.go-ops?=	../../wip/go-ops

.include "../../wip/go-context/buildlink3.mk"
.endif	# GO_OPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-ops
