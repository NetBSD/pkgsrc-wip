# $NetBSD: buildlink3.mk,v 1.1 2015/03/29 13:44:15 leot1990 Exp $

BUILDLINK_TREE+=	libcsv

.if !defined(LIBCSV_BUILDLINK3_MK)
LIBCSV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcsv+=	libcsv>=3.0.3
BUILDLINK_PKGSRCDIR.libcsv?=	../../wip/libcsv
.endif	# LIBCSV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcsv
