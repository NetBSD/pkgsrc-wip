# $NetBSD: buildlink3.mk,v 1.5 2012/11/05 13:52:38 othyro Exp $

BUILDLINK_TREE+=	dssi

.if !defined(DSSI_BUILDLINK3_MK)
DSSI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.dssi+=	dssi>=1.1.1
BUILDLINK_PKGSRCDIR.dssi?=	../../wip/dssi
BUILDLINK_DEPMETHOD.dssi?=	build

pkgbase := dssi
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS:Mqt)
.include "../../x11/qt4-libs/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../wip/libdssialsacompat/buildlink3.mk"
.include "../../wip/liblo/buildlink3.mk"
.endif # DSSI_BUILDLINK3_MK

BUILDLINK_TREE+=	-dssi
