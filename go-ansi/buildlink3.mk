# $NetBSD$

BUILDLINK_TREE+=	go-ansi

.if !defined(GO_ANSI_BUILDLINK3_MK)
GO_ANSI_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-ansi=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-ansi?=		build

BUILDLINK_API_DEPENDS.go-ansi+=	go-ansi>=20200706
BUILDLINK_PKGSRCDIR.go-ansi?=	../../wip/go-ansi


.include "../../devel/go-colorable/buildlink3.mk"
.endif	# GO_ANSI_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-ansi
