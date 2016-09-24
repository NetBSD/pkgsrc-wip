# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/08/05 10:20:22 jihbed Exp $

BUILDLINK_TREE+=	aravis

.if !defined(ARAVIS_BUILDLINK3_MK)
ARAVIS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aravis+=	aravis>=0.1.0
BUILDLINK_PKGSRCDIR.aravis?=	../../wip/aravis

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif	# ARAVIS_BUILDLINK3_MK

BUILDLINK_TREE+=	-aravis
