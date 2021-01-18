# $NetBSD$

BUILDLINK_TREE+=	go-hidden

.if !defined(GO_HIDDEN_BUILDLINK3_MK)
GO_HIDDEN_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-hidden=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-hidden?=		build

BUILDLINK_API_DEPENDS.go-hidden+=	go-hidden>=20201230
BUILDLINK_PKGSRCDIR.go-hidden?=	../../wip/go-hidden

.include "../../wip/go-hex/buildlink3.mk"
.endif	# GO_HIDDEN_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-hidden
