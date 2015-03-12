# $NetBSD: buildlink3.mk,v 1.1 2015/03/12 21:06:12 tnn2 Exp $

BUILDLINK_TREE+=	go-fsnotify

.if !defined(GO_FSNOTIFY_BUILDLINK3_MK)
GO_FSNOTIFY_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.go-fsnotify?=	build
BUILDLINK_API_DEPENDS.go-fsnotify+=	go-fsnotify>=1.2.0
BUILDLINK_PKGSRCDIR.go-fsnotify?=	../../wip/go-fsnotify

.endif	# GO_FSNOTIFY_BUILDLINK3_MK

BUILDLINK_TREE+=	-go-fsnotify
