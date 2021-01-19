# $NetBSD$

BUILDLINK_TREE+=	go-genny

.if !defined(GO_GENNY_BUILDLINK3_MK)
GO_GENNY_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-genny=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-genny?=		build

BUILDLINK_API_DEPENDS.go-genny+=	go-genny>=20200409
BUILDLINK_PKGSRCDIR.go-genny?=		../../wip/go-genny

.include "../../devel/go-mod/buildlink3.mk"
.include "../../devel/go-tools/buildlink3.mk"
.endif	# GO_GENNY_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-genny
