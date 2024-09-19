# $NetBSD$

BUILDLINK_TREE+=	template-glib

.if !defined(TEMPLATE_GLIB_BUILDLINK3_MK)
TEMPLATE_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.template-glib+=	template-glib>=3.34.0
BUILDLINK_PKGSRCDIR.template-glib?=	../../wip/template-glib

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# TEMPLATE_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-template-glib
