# $NetBSD$

BUILDLINK_TREE+=	trafficserver

.if !defined(TRAFFICSERVER_BUILDLINK3_MK)
TRAFFICSERVER_BUILDLINK3_MK:=

# XXX
# XXX Packages that only install static libraries or headers should
# XXX include the following line:
# XXX
# XXX	BUILDLINK_DEPMETHOD.trafficserver?=	build

BUILDLINK_API_DEPENDS.trafficserver+=	trafficserver>=10.2.1
BUILDLINK_PKGSRCDIR.trafficserver?=	../../wip/trafficserver

# XXX
# XXX Uncomment and keep only the buildlink3 lines below which are directly
# XXX needed for dependencies to compile, link, and run.  If this package
# XXX provides a wrappered API or otherwise does not expose the APIs of the
# XXX buildlink3 lines below to dependencies, remove them.
# XXX
#.include "../../archivers/lzmalib/buildlink3.mk"
#.include "../../archivers/brotli/buildlink3.mk"
#.include "../../archivers/xz/buildlink3.mk"
#.include "../../devel/pcre2/buildlink3.mk"
#.include "../../lang/LuaJIT2/buildlink3.mk"
#.include "../../devel/jemalloc/buildlink3.mk"
#.include "../../textproc/yaml-cpp/buildlink3.mk"
.endif	# TRAFFICSERVER_BUILDLINK3_MK

BUILDLINK_TREE+=	-trafficserver
