# $NetBSD: buildlink3.mk,v 1.2 2011/07/12 09:58:49 phonohawk Exp $

BUILDLINK_TREE+=	hs-glib

.if !defined(HS_GLIB_BUILDLINK3_MK)
HS_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-glib+=	hs-glib>=0.12
BUILDLINK_PKGSRCDIR.hs-glib?=	../../wip/hs-glib

.include "../../devel/glib2/buildlink3.mk"
.endif	# HS_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-glib
