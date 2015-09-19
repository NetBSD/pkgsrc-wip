# $NetBSD: buildlink3.mk,v 1.1 2015/09/19 15:12:54 tnn2 Exp $

BUILDLINK_TREE+=	waffle

.if !defined(WAFFLE_BUILDLINK3_MK)
WAFFLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.waffle+=	waffle>=1.5.2
BUILDLINK_PKGSRCDIR.waffle?=	../../wip/waffle

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# WAFFLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-waffle
