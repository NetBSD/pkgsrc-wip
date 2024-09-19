# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/06/12 23:24:04 jihbed Exp $

BUILDLINK_TREE+=	discident-glib

.if !defined(DISCIDENT_GLIB_BUILDLINK3_MK)
DISCIDENT_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.discident-glib+=	discident-glib>=0.9.9
BUILDLINK_PKGSRCDIR.discident-glib?=	../../wip/discident-glib

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.endif	# DISCIDENT_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-discident-glib
