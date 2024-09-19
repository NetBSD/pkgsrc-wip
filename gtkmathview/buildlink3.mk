# $NetBSD: buildlink3.mk,v 1.1 2014/12/26 21:16:29 nros Exp $
#

BUILDLINK_TREE+=	gtkmathview

.if !defined(GTKMATHVIEW_BUILDLINK3_MK)
GTKMATHVIEW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtkmathview+=	gtkmathview>=0.8.0
BUILDLINK_PKGSRCDIR.gtkmathview?=	../../wip/gtkmathview

.include "../../fonts/t1lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/gmetadom/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif	# GTKMATHVIEW_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtkmathview
