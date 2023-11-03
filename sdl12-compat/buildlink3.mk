# $NetBSD$
# XXX
# XXX This file was created automatically using createbuildlink-3.19.
# XXX After this file has been verified as correct, the comment lines
# XXX beginning with "XXX" should be removed.  Please do not commit
# XXX unverified buildlink3.mk files.

BUILDLINK_TREE+=	sdl12-compat

.if !defined(SDL12_COMPAT_BUILDLINK3_MK)
SDL12_COMPAT_BUILDLINK3_MK:=

# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.sdl12-compat?=	build

BUILDLINK_API_DEPENDS.sdl12-compat+=	sdl12-compat>=1.2.52nb3
BUILDLINK_PKGSRCDIR.sdl12-compat?=	../../wip/sdl12-compat

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../devel/SDL2/buildlink3.mk"
.endif	# SDL12_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-sdl12-compat
