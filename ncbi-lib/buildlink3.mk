# $NetBSD: buildlink3.mk,v 1.11 2009/06/02 14:36:42 noud4 Exp $

BUILDLINK_TREE+=	ncbi-lib

.if !defined(NCBI_LIB_BUILDLINK3_MK)
NCBI_LIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ncbi-lib+=	ncbi-lib>=20060301
BUILDLINK_PKGSRCDIR.ncbi-lib?=		../../wip/ncbi-lib

.include "../../mk/bsd.fast.prefs.mk"

.if ${X11_TYPE} == "modular"
.include "../../x11/libX11/buildlink3.mk"
.else
.include "../../mk/x11.buildlink3.mk"
.endif # X11_TYPE
.endif # NCBI_LIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-ncbi-lib
