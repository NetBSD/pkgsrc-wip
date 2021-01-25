# $NetBSD$

BUILDLINK_TREE+=	go-randomdata

.if !defined(GO_RANDOMDATA_BUILDLINK3_MK)
GO_RANDOMDATA_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-randomdata=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-randomdata?=		build

BUILDLINK_API_DEPENDS.go-randomdata+=	go-randomdata>=1.2.0
BUILDLINK_PKGSRCDIR.go-randomdata?=	../../wip/go-randomdata
.endif	# GO_RANDOMDATA_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-randomdata
