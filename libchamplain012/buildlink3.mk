# $NetBSD: buildlink3.mk,v 1.1 2014/12/25 15:30:50 nros Exp $
#

BUILDLINK_TREE+=	libchamplain012

.if !defined(LIBCHAMPLAIN012_BUILDLINK3_MK)
LIBCHAMPLAIN012_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libchamplain012+=	libchamplain012>=0.12.9
BUILDLINK_PKGSRCDIR.libchamplain012?=	../../wip/libchamplain012

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../wip/libmemphis02/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBCHAMPLAIN012_BUILDLINK3_MK

BUILDLINK_TREE+=	-libchamplain012
