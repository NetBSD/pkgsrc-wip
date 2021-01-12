# $NetBSD$

BUILDLINK_TREE+=	go-imgui

.if !defined(GO_IMGUI_BUILDLINK3_MK)
GO_IMGUI_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-imgui=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-imgui?=		build

BUILDLINK_API_DEPENDS.go-imgui+=	go-imgui>=3.0.0
BUILDLINK_PKGSRCDIR.go-imgui?=		../../wip/go-imgui
.endif	# GO_IMGUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-imgui
