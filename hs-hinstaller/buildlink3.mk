# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/02/26 10:16:20 phonohawk Exp $

BUILDLINK_TREE+=	hs-hinstaller

.if !defined(HS_HINSTALLER_BUILDLINK3_MK)
HS_HINSTALLER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hinstaller+=	hs-hinstaller>=2008.2.16
BUILDLINK_PKGSRCDIR.hs-hinstaller?=	../../wip/hs-hinstaller
.endif	# HS_HINSTALLER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hinstaller
