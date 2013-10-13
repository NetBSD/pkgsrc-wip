# $NetBSD: buildlink3.mk,v 1.1 2013/10/13 09:47:13 leot1990 Exp $

BUILDLINK_TREE+=	mupdf

.if !defined(MUPDF_BUILDLINK3_MK)
MUPDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mupdf+=	mupdf>=0.0.937
BUILDLINK_PKGSRCDIR.mupdf?=	../../print/mupdf

.endif	# MUPDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-mupdf
