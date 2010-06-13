# $NetBSD: buildlink3.mk,v 1.3 2010/06/13 22:46:57 thomasklausner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.13.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.beryl-core?=	build

BUILDLINK_TREE+=	beryl-core

.if !defined(BERYL_CORE_BUILDLINK3_MK)
BERYL_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.beryl-core+=	beryl-core>=0.2.1
BUILDLINK_ABI_DEPENDS.beryl-core?=	beryl-core>=0.2.1nb2
BUILDLINK_PKGSRCDIR.beryl-core?=	../../wip/beryl-core

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.endif # BERYL_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-beryl-core
