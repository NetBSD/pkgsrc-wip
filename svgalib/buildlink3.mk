# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:52 jsonn Exp $

BUILDLINK_TREE+=	svgalib

BUILDLINK_API_DEPENDS.svgalib+=	svgalib>=1.4.2
BUILDLINK_PKGSRCDIR.svgalib?=	../../wip/svgalib
.endif # SVGALIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-svgalib
