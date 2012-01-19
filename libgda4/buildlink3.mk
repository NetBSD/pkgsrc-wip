# $NetBSD: buildlink3.mk,v 1.3 2012/01/19 16:43:00 noud4 Exp $

BUILDLINK_TREE+=	libgda

.if !defined(LIBGDA_BUILDLINK3_MK)
LIBGDA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgda+=	libgda>=4.0.0
BUILDLINK_ABI_DEPENDS.libgda+=	libgda>=4.0.0
BUILDLINK_PKGSRCDIR.libgda?=	../../wip/libgda4

PRINT_PLIST_AWK+=	/^@dirrm lib\/libgda-4.0\/providers$$/ \
				{ print "@comment in libgda: " $$0; next; }
PRINT_PLIST_AWK+=	/^@dirrm share\/libgda-4.0$$/ \
				{ print "@comment in libgda: " $$0; next; }

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := libgda
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.libgda:Mfam)
.include "../../mk/fam.buildlink3.mk"
.endif

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBGDA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgda
