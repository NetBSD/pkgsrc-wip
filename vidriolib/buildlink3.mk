# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:53 jsonn Exp $

BUILDLINK_TREE+=	vidriolib

.if !defined(VIDRIOLIB_BUILDLINK3_MK)
VIDRIOLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vidriolib+=	vidriolib>=0.1.20070715.0
BUILDLINK_PKGSRCDIR.vidriolib?=		../../wip/vidriolib

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.endif # VIDRIOLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-vidriolib
