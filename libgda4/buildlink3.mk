# $NetBSD: buildlink3.mk,v 1.4 2012/06/10 10:16:22 noud4 Exp $

BUILDLINK_TREE+=	libgda4

.if !defined(LIBGDA4_BUILDLINK3_MK)
LIBGDA4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgda4+=	libgda4>=4.0.0
BUILDLINK_ABI_DEPENDS.libgda4+=	libgda4>=4.0.0
BUILDLINK_PKGSRCDIR.libgda4?=	../../wip/libgda4

PRINT_PLIST_AWK+=	/^@dirrm lib\/libgda4-4.0\/providers$$/ \
				{ print "@comment in libgda4: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/libgda4-4.0$$/ \
				{ print "@comment in libgda4: " $$0; next; }

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := libgda4
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libgda4:Mfam)
.include "../../mk/fam.buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.libgda4:Mui) || !empty(PKG_BUILD_OPTIONS.libgda4:Mgui)
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBGDA4_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgda4
