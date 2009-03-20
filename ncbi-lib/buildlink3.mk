# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:43:51 jsonn Exp $

BUILDLINK_TREE+=	ncbi-lib

BUILDLINK_API_DEPENDS.ncbi-lib+=	ncbi-lib>=20060301
BUILDLINK_PKGSRCDIR.ncbi-lib?=	../../wip/ncbi-lib
.endif # NCBI_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncbi-lib
