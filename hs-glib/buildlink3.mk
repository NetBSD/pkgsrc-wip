# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/07/12 09:47:40 phonohawk Exp $

BUILDLINK_TREE+=	hs-glib

.if !defined(HS_GLIB_BUILDLINK3_MK)
HS_GLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-glib+=	hs-glib>=0.12
BUILDLINK_PKGSRCDIR.hs-glib?=	../../wip/hs-glib

.endif	# HS_GLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-glib
