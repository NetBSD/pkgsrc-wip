# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/04/18 00:26:48 jihbed Exp $

BUILDLINK_TREE+=	taglib-sharp

.if !defined(TAGLIB_SHARP_BUILDLINK3_MK)
TAGLIB_SHARP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.taglib-sharp+=	taglib-sharp>=2.0.3.2
BUILDLINK_PKGSRCDIR.taglib-sharp?=	../../wip/taglib-sharp


.include "../../lang/mono/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.endif	# TAGLIB_SHARP_BUILDLINK3_MK

BUILDLINK_TREE+=	-taglib-sharp
