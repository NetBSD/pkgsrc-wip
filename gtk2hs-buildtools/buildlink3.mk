# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/12 08:43:14 phonohawk Exp $

BUILDLINK_TREE+=	hs-gtk2hs-buildtools

.if !defined(HS_GTK2HS_BUILDTOOLS_BUILDLINK3_MK)
HS_GTK2HS_BUILDTOOLS_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hs-gtk2hs-buildtools?=	build
BUILDLINK_API_DEPENDS.hs-gtk2hs-buildtools+=	hs-gtk2hs-buildtools>=0.12
BUILDLINK_PKGSRCDIR.hs-gtk2hs-buildtools?=	../../wip/gtk2hs-buildtools
.endif	# HS_GTK2HS_BUILDTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-gtk2hs-buildtools
