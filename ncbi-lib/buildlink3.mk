# $NetBSD: buildlink3.mk,v 1.10 2009/06/02 13:14:30 noud4 Exp $

BUILDLINK_TREE+=	ncbi-lib

.if !defined(NCBI_LIB_BUILDLINK3_MK)
NCBI_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ncbi-lib+=	ncbi-lib>=20060301
BUILDLINK_PKGSRCDIR.ncbi-lib?=		../../wip/ncbi-lib

.if ${X11_TYPE} == "modular"
.include "../../x11/libX11/buildlink3.mk"
.endif # X11_TYPE
.endif # NCBI_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncbi-lib
