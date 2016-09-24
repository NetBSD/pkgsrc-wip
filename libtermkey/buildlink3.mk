# $NetBSD: buildlink3.mk,v 1.1 2015/02/21 16:22:20 jonthn Exp $

BUILDLINK_TREE+=	libtermkey

.if !defined(LIBTERMKEY_BUILDLINK3_MK)
LIBTERMKEY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtermkey+=	libtermkey>=0.17
BUILDLINK_PKGSRCDIR.libtermkey?=	../../wip/libtermkey

pkgbase := libtermkey
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.termkey:Mncurses)
.include "../../mk/termcap.buildlink3.mk"
.endif
.if !empty(PKG_BUILD_OPTIONS.termkey:Munibilium)
.include "../../wip/libunibilium/buildlink3.mk"
.endif


.endif	# LIBTERMKEY_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtermkey
