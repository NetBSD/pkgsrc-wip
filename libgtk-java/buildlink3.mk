# $NetBSD: buildlink3.mk,v 1.6 2010/06/13 22:47:10 thomasklausner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.12.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.libgtk-java?=	build

BUILDLINK_TREE+=	libgtk-java

.if !defined(uibgtk_java_BUILDLINK3_MK)
uibgtk_java_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgtk-java+=	libgtk-java>=2.8.5
BUILDLINK_ABI_DEPENDS.libgtk-java?=	libgtk-java>=2.8.5nb1
BUILDLINK_PKGSRCDIR.libgtk-java?=	../../wip/libgtk-java

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../wip/glib-java/buildlink3.mk"
.include "../../wip/cairo-java/buildlink3.mk"
#.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # uibgtk_java_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgtk-java
