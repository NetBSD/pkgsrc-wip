# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/05/23 15:34:40 jihbed Exp $

BUILDLINK_TREE+=	gtksourcecompletion

.if !defined(GTKSOURCECOMPLETION_BUILDLINK3_MK)
GTKSOURCECOMPLETION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtksourcecompletion+=	gtksourcecompletion>=0.5.2
BUILDLINK_PKGSRCDIR.gtksourcecompletion?=	../../wip/gtksourcecompletion

.include "../../x11/gtksourceview2/buildlink3.mk"

.endif	# GTKSOURCECOMPLETION_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtksourcecompletion
