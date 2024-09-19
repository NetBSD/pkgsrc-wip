# $NetBSD: buildlink3.mk,v 1.7 2014/05/21 21:04:46 szptvlfn Exp $

BUILDLINK_TREE+=	hs-x11-extras

.if !defined(HS_X11_EXTRAS_BUILDLINK3_MK)
HS_X11_EXTRAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-x11-extras+=	hs-x11-extras>=0.4
BUILDLINK_ABI_DEPENDS.hs-x11-extras?=	hs-x11-extras>=0.4nb1
BUILDLINK_PKGSRCDIR.hs-x11-extras?=	../../wip/hs-x11-extras

.include "../../x11/hs-X11/buildlink3.mk"
.include "../../lang/ghc/buildlink3.mk"
.endif # HS_X11_EXTRAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-x11-extras
