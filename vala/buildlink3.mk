# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:53 jsonn Exp $

BUILDLINK_TREE+=	vala

.if !defined(VALA_BUILDLINK3_MK)
VALA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vala+=	vala>=0.3.5
BUILDLINK_PKGSRCDIR.vala?=	../../wip/vala

.include "../../devel/glib2/buildlink3.mk"
.endif # VALA_BUILDLINK3_MK

BUILDLINK_TREE+=	-vala
