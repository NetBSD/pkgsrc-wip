# $NetBSD: buildlink3.mk,v 1.5 2012/11/06 14:45:00 othyro Exp $

BUILDLINK_TREE+=	twinkle

.if !defined(TWINKLE_BUILDLINK3_MK)
TWINKLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.twinkle+=	twinkle>=1.1
BUILDLINK_ABI_DEPENDS.twinkle?=	twinkle>=1.4.2nb4
BUILDLINK_PKGSRCDIR.twinkle?=	../../wip/twinkle

pkgbase := twinkle
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS:Milbc)
.include "../../wip/ilbc-rfc3951/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mkde)
.include "../../x11/kdelibs3/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mspeex)
.include "../../audio/speex/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS:Mzrtp)
.include "../../wip/libzrtpcpp/buildlink3.mk"
.endif

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../wip/ccrtp/buildlink3.mk"
.endif # TWINKLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-twinkle
