# $NetBSD$

BUILDLINK_TREE+=	gcr4

.if !defined(GCR4_BUILDLINK3_MK)
GCR4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcr4+=	gcr4>=4.3.0
BUILDLINK_PKGSRCDIR.gcr4?=	../../wip/gcr4

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/libsecret/buildlink3.mk"
.include "../../security/p11-kit/buildlink3.mk"

pkgbase :=      gcr4
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.gcr4:Mgtk4}
.  include "../../x11/gtk4/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.gcr4:Mintrospection}
.  include "../../devel/gobject-introspection/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.gcr4:Mlibgcrypt}
.  include "../../security/libgcrypt/buildlink3.mk"
.elif ${PKG_BUILD_OPTIONS.gcr4:Mgnutls}
.  include "../../security/gnutls/buildlink3.mk"
.endif

.endif	# GCR4_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcr4
