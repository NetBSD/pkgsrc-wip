# $NetBSD$

BUILDLINK_TREE+=	nlopt

.if !defined(NLOPT_BUILDLINK3_MK)
NLOPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.nlopt+=	nlopt>=2.9.1
BUILDLINK_ABI_DEPENDS.nlopt+=	nlopt>=2.9.1
BUILDLINK_PKGSRCDIR.nlopt?=	../../wip/nlopt

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := nlopt
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.nlopt:Mguile}
.  include "../../lang/guile30/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.nlopt:Moctave}
.  include "../../math/octave/buildlink3.mk"
.endif

.if ${PKG_BUILD_OPTIONS.nlopt:Mpython}
.  include "../../lang/python/extension.mk"
.endif

.include "../../devel/gmp/buildlink3.mk"
.endif # NLOPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-nlopt
