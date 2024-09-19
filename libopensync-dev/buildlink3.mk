# $NetBSD: buildlink3.mk,v 1.1 2013/02/24 13:41:22 othyro Exp $

BUILDLINK_TREE+=	libopensync-dev

.if !defined(LIBOPENSYNC_DEV_BUILDLINK3_MK)
LIBOPENSYNC_DEV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libopensync-dev+=	libopensync-dev>=0.39
BUILDLINK_PKGSRCDIR.libopensync-dev?=	../../wip/libopensync-dev

pkgbase := libopensync-dev
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libopensync-dev:Mpython)
.include "../../devel/swig/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.libopensync-dev:Mtests)
.include "../../devel/check/buildlink3.mk"
.endif

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.endif	# LIBOPENSYNC_DEV_BUILDLINK3_MK

BUILDLINK_TREE+=	-libopensync-dev
