# $NetBSD: buildlink3.mk,v 1.85 2024/11/17 07:15:45 wiz Exp $

BUILDLINK_TREE+=	libgweather4

.if !defined(LIBGWEATHER4_BUILDLINK3_MK)
LIBGWEATHER4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgweather4+=	libgweather4>=4.4
BUILDLINK_ABI_DEPENDS.libgweather4+=	libgweather4>=4.4
BUILDLINK_PKGSRCDIR.libgweather4?=	../../wip/libgweather4

.include "../../wip/geocode-glib2/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.endif # LIBGWEATHER4_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgweather4
