# $NetBSD: buildlink3.mk,v 1.7 2009/05/06 10:47:32 cheusov Exp $

BUILDLINK_TREE+=	GtkAda

.if !defined(GTKADA_BUILDLINK3_MK)
GTKADA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.GtkAda+=	GtkAda>=2.2.1
BUILDLINK_ABI_DEPENDS.GtkAda?=	GtkAda>=2.2.1nb2
BUILDLINK_PKGSRCDIR.GtkAda?=	../../wip/gtkada

.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.endif # GTKADA_BUILDLINK3_MK

BUILDLINK_TREE+=	-GtkAda
