# $NetBSD$

BUILDLINK_TREE+=	go-uuid-myesui

.if !defined(GO_UUID_MYESUI_BUILDLINK3_MK)
GO_UUID_MYESUI_BUILDLINK3_MK:=

BUILDLINK_CONTENTS_FILTER.go-uuid-myesui=	${EGREP} gopkg/
BUILDLINK_DEPMETHOD.go-uuid-myesui?=		build

BUILDLINK_API_DEPENDS.go-uuid-myesui+=	go-uuid-myesui>=1.0.0
BUILDLINK_PKGSRCDIR.go-uuid-myesui?=	../../wip/go-uuid-myesui
.endif	# GO_UUID_MYESUI_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-uuid-myesui
