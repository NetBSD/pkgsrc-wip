# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/11/06 12:40:09 grasmi Exp $

BUILDLINK_TREE+=	libvalhalla

.if !defined(LIBVALHALLA_BUILDLINK3_MK)
LIBVALHALLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvalhalla+=	libvalhalla>=1.0.1
BUILDLINK_PKGSRCDIR.libvalhalla?=	../../wip/libvalhalla

.include "../../wip/libnfo/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.endif	# LIBVALHALLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvalhalla
