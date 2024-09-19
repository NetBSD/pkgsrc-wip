# $NetBSD: buildlink3.mk,v 1.5 2013/03/03 17:27:54 othyro Exp $

BUILDLINK_TREE+=	pxlib

.if !defined(PXLIB_BUILDLINK3_MK)
PXLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pxlib+=	pxlib>=0.2.0
BUILDLINK_PKGSRCDIR.pxlib?=	../../wip/pxlib

pkgbase := pxlib
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.pxlib:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/recode/buildlink3.mk"
.endif # PXLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-pxlib
