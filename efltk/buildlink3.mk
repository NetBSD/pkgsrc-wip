# $NetBSD: buildlink3.mk,v 1.4 2010/12/26 05:01:21 davesainty Exp $

BUILDLINK_TREE+=	efltk

.if !defined(EFLTK_BUILDLINK3_MK)
EFLTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.efltk+=	efltk>=2.0.5nb1
BUILDLINK_ABI_DEPENDS.efltk?=	efltk>=2.0.8nb2
BUILDLINK_PKGSRCDIR.efltk?=	../../x11/efltk

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.endif # EFLTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-efltk
