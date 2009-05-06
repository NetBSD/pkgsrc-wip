# $NetBSD: buildlink3.mk,v 1.8 2009/05/06 09:27:04 cheusov Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.12.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.glib-java?=	build

BUILDLINK_TREE+=	glib-java

.if !defined(GLIB_JAVA_BUILDLINK3_MK)
GLIB_JAVA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glib-java+=	glib-java>=0.2.5
BUILDLINK_PKGSRCDIR.glib-java?=	../../wip/glib-java

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/glib2/buildlink3.mk"

.endif # GLIB_JAVA_BUILDLINK3_MK

BUILDLINK_TREE+=	-glib-java
