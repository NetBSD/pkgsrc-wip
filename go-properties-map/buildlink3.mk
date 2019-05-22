# $NetBSD$
BUILDLINK_TREE+=	go-properties-map

.if !defined(GO_PROPERTIES_MAP_BUILDLINK3_MK)
GO_PROPERTIES_MAP_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-properties-map=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-properties-map?=		build

BUILDLINK_API_DEPENDS.go-properties-map+=	go-properties-map>=0
BUILDLINK_PKGSRCDIR.go-properties-map?=		../../wip/go-properties-map

.include "../../wip/go-paths-helper/buildlink3.mk"
.endif	# GO_PROPERTIES_MAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-properties-map
