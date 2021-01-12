# $NetBSD$

BUILDLINK_TREE+=	go-douceur-aymerick

.if !defined(GO_DOUCEUR_AYMERICK_BUILDLINK3_MK)
GO_DOUCEUR_AYMERICK_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-douceur-aymerick=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-douceur-aymerick?=	build

BUILDLINK_API_DEPENDS.go-douceur-aymerick+=	go-douceur-aymerick>=20180322
BUILDLINK_PKGSRCDIR.go-douceur-aymerick?=	../../wip/go-douceur-aymerick

.include "../../net/go-net/buildlink3.mk"
.include "../../wip/go-cascadia/buildlink3.mk"
.include "../../wip/go-goquery/buildlink3.mk"
.include "../../wip/go-gorilla-css/buildlink3.mk"
.endif	# GO_DOUCEUR_AYMERICK_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-douceur-aymerick
