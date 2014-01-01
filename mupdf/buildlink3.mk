# $NetBSD: buildlink3.mk,v 1.2 2014/01/01 17:28:17 leot1990 Exp $

BUILDLINK_TREE+=	mupdf

.if !defined(MUPDF_BUILDLINK3_MK)
MUPDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mupdf+=	mupdf>=1.3
BUILDLINK_PKGSRCDIR.mupdf?=	../../wip/mupdf

.endif	# MUPDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-mupdf
