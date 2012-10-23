# $NetBSD: buildlink3.mk,v 1.3 2012/10/23 10:23:06 thomasklausner Exp $

BUILDLINK_TREE+=	libdmx

.if !defined(LIBDMX_BUILDLINK3_MK)
LIBDMX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdmx+=	libdmx>=1.0.2
BUILDLINK_PKGSRCDIR.libdmx?=	../../wip/libdmx

.include "../../x11/libXext/buildlink3.mk"
.include "../../wip/dmxproto/buildlink3.mk"
.endif # LIBDMX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdmx
