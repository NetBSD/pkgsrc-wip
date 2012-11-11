# $NetBSD: buildlink3.mk,v 1.7 2012/11/11 13:44:13 othyro Exp $

BUILDLINK_TREE+=	twinkle

.if !defined(TWINKLE_BUILDLINK3_MK)
TWINKLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.twinkle+=	twinkle>=1.1
BUILDLINK_ABI_DEPENDS.twinkle?=	twinkle>=1.4.2nb4
BUILDLINK_PKGSRCDIR.twinkle?=	../../wip/twinkle

pkgbase := twinkle
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.twinkle:Malsa)
.include "../../audio/alsa-lib/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.twinkle:Milbc)
.include "../../wip/ilbc-rfc3951/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.twinkle:Mkde)
.include "../../x11/kdelibs3/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.twinkle:Mspeex)
.include "../../audio/speex/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.twinkle:Mzrtp)
.include "../../wip/libzrtpcpp/buildlink3.mk"
.endif

.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wip/commoncpp2/buildlink3.mk"
.include "../../wip/ccrtp/buildlink3.mk"
.endif # TWINKLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-twinkle
