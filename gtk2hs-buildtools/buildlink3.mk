# $NetBSD: buildlink3.mk,v 1.6 2014/08/29 14:09:59 szptvlfn Exp $

BUILDLINK_TREE+=	gtk2hs-buildtools

.if !defined(GTK2HS_BUILDTOOLS_BUILDLINK3_MK)
GTK2HS_BUILDTOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gtk2hs-buildtools+=	gtk2hs-buildtools>=0.12.3
BUILDLINK_ABI_DEPENDS.gtk2hs-buildtools+=	gtk2hs-buildtools>=0.12.3
BUILDLINK_PKGSRCDIR.gtk2hs-buildtools?=		../../wip/gtk2hs-buildtools

.include "../../devel/hs-random/buildlink3.mk"
.endif	# GTK2HS_BUILDTOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gtk2hs-buildtools
