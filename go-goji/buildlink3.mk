# $NetBSD$

BUILDLINK_TREE+=	go-goji

.if !defined(GO_GOJI_BUILDLINK3_MK)
GO_GOJI_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-goji=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-goji?=		build

BUILDLINK_API_DEPENDS.go-goji+=	go-goji>=1.0.1
BUILDLINK_PKGSRCDIR.go-goji?=	../../category/go-goji

.include "../../wip/go-param/buildlink3.mk"
.endif	# GO_GOJI_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-goji
