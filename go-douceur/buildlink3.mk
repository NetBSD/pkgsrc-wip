# $NetBSD$

BUILDLINK_TREE+=	go-douceur

.if !defined(GO_DOUCEUR_BUILDLINK3_MK)
GO_DOUCEUR_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-douceur=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-douceur?=	build

BUILDLINK_API_DEPENDS.go-douceur+=	go-douceur>=20180322
BUILDLINK_PKGSRCDIR.go-douceur?=	../../wip/go-douceur

.include "../../net/go-net/buildlink3.mk"
.include "../../wip/go-cascadia/buildlink3.mk"
.include "../../wip/go-goquery/buildlink3.mk"
.include "../../wip/go-gorilla-css/buildlink3.mk"
.endif	# GO_DOUCEUR_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-douceur
