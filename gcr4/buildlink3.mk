# $NetBSD$

BUILDLINK_TREE+=	gcr

.if !defined(GCR_BUILDLINK3_MK)
GCR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcr+=	gcr>=4.3.0
BUILDLINK_PKGSRCDIR.gcr?=	../../wip/gcr4

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/p11-kit/buildlink3.mk"

pkgbase :=      gcr
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.gcr:Mgtk4}
.  include "../../x11/gtk4/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.gcr:Mintrospection}
.  include "../../devel/gobject-introspection/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.gcr:Mlibgcrypt}
.  include "../../security/libgcrypt/buildlink3.mk"
.elif ${PKG_BUILD_OPTIONS.gcr:Mgnutls}
.  include "../../security/gnutls/buildlink3.mk"
.endif

.endif	# GCR_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcr
