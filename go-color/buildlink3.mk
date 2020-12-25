# $NetBSD$

BUILDLINK_TREE+=	go-color

.if !defined(GO_COLOR_BUILDLINK3_MK)
GO_COLOR_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-color=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-color?=		build

BUILDLINK_API_DEPENDS.go-color+=	go-color>=1.10.0
BUILDLINK_PKGSRCDIR.go-color?=	../../wip/go-color

.include "../../devel/go-colorable/buildlink3.mk"
.include "../../devel/go-isatty/buildlink3.mk"
.endif	# GO_COLOR_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-color
