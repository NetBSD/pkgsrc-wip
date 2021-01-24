# $NetBSD$
#

BUILDLINK_TREE+=	vulkan-loader

.if !defined(VULKAN_LOADER_BUILDLINK3_MK)
VULKAN_LOADER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vulkan-loader+=	vulkan-loader>=1.1.126.0
BUILDLINK_PKGSRCDIR.vulkan-loader?=	../../wip/vulkan-loader

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
.include "../../graphics/vulkan-headers/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.endif	# VULKAN_LOADER_BUILDLINK3_MK

BUILDLINK_TREE+=	-vulkan-loader
