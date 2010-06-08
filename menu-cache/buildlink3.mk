# $NetBSD: buildlink3.mk,v 1.2 2010/06/08 16:05:09 thomasklausner Exp $
# XXX
# XXX This file was created automatically using createbuildlink-3.14.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.
# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.menu-cache?=	build

BUILDLINK_TREE+=	menu-cache

.if !defined(MENU_CACHE_BUILDLINK3_MK)
MENU_CACHE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.menu-cache+=	menu-cache>=0.2.3
BUILDLINK_PKGSRCDIR.menu-cache?=	../../wip/menu-cache

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/glib2/buildlink3.mk"
.endif	# MENU_CACHE_BUILDLINK3_MK

BUILDLINK_TREE+=	-menu-cache
