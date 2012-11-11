# $NetBSD: buildlink3.mk,v 1.4 2012/11/11 13:44:13 othyro Exp $

BUILDLINK_TREE+=	tkhtml3

.if !defined(TKHTML3_BUILDLINK3_MK)
TKHTML3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.tkhtml3+=	tkhtml3>=1.0alpha16
BUILDLINK_PKGSRCDIR.tkhtml3?=	../../wip/tkhtml3

pkgbase := tkhtml3
.include "../../mk/pkg-build-options.mk"


.if !empty(PKG_BUILD_OPTIONS.tkhtml3:Mpthread)
.include "../../mk/pthread.buildlink3.mk"
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.endif	# TKHTML3_BUILDLINK3_MK

BUILDLINK_TREE+=	-tkhtml3
