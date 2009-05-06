# $NetBSD: buildlink3.mk,v 1.9 2009/05/06 09:29:04 cheusov Exp $

BUILDLINK_TREE+=	ncbi-lib

.if !defined(NCBI_LIB_BUILDLINK3_MK)
NCBI_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ncbi-lib+=	ncbi-lib>=20060301
BUILDLINK_PKGSRCDIR.ncbi-lib?=		../../wip/ncbi-lib

.endif # NCBI_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncbi-lib
