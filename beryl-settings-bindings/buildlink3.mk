# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:39 jsonn Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.13.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.beryl-settings-bindings?=	build

BUILDLINK_TREE+=	beryl-settings-bindings

.if !defined(BERYL_SETTINGS_BINDINGS_BUILDLINK3_MK)
BERYL_SETTINGS_BINDINGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.beryl-settings-bindings+=	beryl-settings-bindings>=0.2.1
BUILDLINK_PKGSRCDIR.beryl-settings-bindings?=	../../wip/beryl-settings-bindings

.include "../../wip/beryl-core/buildlink3.mk"
.endif # BERYL_SETTINGS_BINDINGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-beryl-settings-bindings
