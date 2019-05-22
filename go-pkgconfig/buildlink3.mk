# $NetBSD$

BUILDLINK_TREE+=	go-pkgconfig

.if !defined(GO_PKGCONFIG_BUILDLINK3_MK)
GO_PKGCONFIG_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-pkgconfig=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-pkgconfig?=	build

BUILDLINK_API_DEPENDS.go-pkgconfig+=	go-pkgconfig>=0.0.0
BUILDLINK_PKGSRCDIR.go-pkgconfig?=	../../wip/go-pkgconfig
.endif	# GO_PKGCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-pkgconfig
