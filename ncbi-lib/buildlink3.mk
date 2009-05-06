# $NetBSD: buildlink3.mk,v 1.8 2009/05/06 09:16:11 cheusov Exp $

BUILDLINK_TREE+=	ncbi-lib

BUILDLINK_API_DEPENDS.ncbi-lib+=	ncbi-lib>=20060301
BUILDLINK_PKGSRCDIR.ncbi-lib?=	../../wip/ncbi-lib

BUILDLINK_TREE+=	-ncbi-lib
