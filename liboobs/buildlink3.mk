# $NetBSD: buildlink3.mk,v 1.4 2015/04/10 12:24:56 krytarowski Exp $

BUILDLINK_TREE+=	liboobs

.if !defined(LIBOOBS_BUILDLINK3_MK)
LIBOOBS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.liboobs+=	liboobs>=2.32.0
BUILDLINK_PKGSRCDIR.liboobs?=	../../wip/liboobs
pkgbase := liboobs
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.liboobs:Mhal)
.include "../../sysutils/hal/buildlink3.mk"
.endif
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif # LIBOOBS_BUILDLINK3_MK

BUILDLINK_TREE+=	-liboobs
