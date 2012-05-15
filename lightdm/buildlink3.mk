# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/05/15 03:29:36 jeremy-c-reed Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.14.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.lightdm?=	build

BUILDLINK_TREE+=	lightdm

.if !defined(LIGHTDM_BUILDLINK3_MK)
LIGHTDM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.lightdm+=	lightdm>=1.2.2
BUILDLINK_PKGSRCDIR.lightdm?=	../../wip/lightdm

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libxklavier/buildlink3.mk"
.endif	# LIGHTDM_BUILDLINK3_MK

BUILDLINK_TREE+=	-lightdm
