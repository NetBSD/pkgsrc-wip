# $NetBSD: buildlink3.mk,v 1.0 2024/11/14 16:30:00 dkazankov Exp $

BUILDLINK_TREE+=	gnat-glade

.if !defined(GNAT_GLADE_BUILDLINK3_MK)
GNAT_GLADE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnat-glade+=	gnat-glade>=6.0.1
BUILDLINK_PKGSRCDIR.gnat-glade?=	../../wip/gnat-glade
BUILDLINK_DEPMETHOD.gnat-glade?=	build

.endif

BUILDLINK_TREE+=	-gnat-glade
