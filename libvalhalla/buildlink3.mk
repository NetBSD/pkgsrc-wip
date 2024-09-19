# $NetBSD: buildlink3.mk,v 1.2 2014/08/11 23:10:13 thomasklausner Exp $

BUILDLINK_TREE+=	libvalhalla

.if !defined(LIBVALHALLA_BUILDLINK3_MK)
LIBVALHALLA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libvalhalla+=	libvalhalla>=1.0.1
BUILDLINK_PKGSRCDIR.libvalhalla?=	../../wip/libvalhalla

.include "../../wip/libnfo/buildlink3.mk"
.include "../../multimedia/ffmpeg1/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.endif	# LIBVALHALLA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libvalhalla
