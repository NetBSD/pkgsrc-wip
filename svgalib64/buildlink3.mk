# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 09:36:48 cheusov Exp $

BUILDLINK_TREE+=	svgalib

.if !defined(SVGALIB_BUILDLINK3_MK)
SVGALIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.svgalib+=	svgalib>=1.4.2
BUILDLINK_PKGSRCDIR.svgalib?=	../../wip/svgalib
.endif # SVGALIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-svgalib
