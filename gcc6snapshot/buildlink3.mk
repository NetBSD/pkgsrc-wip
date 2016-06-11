# $NetBSD: buildlink3.mk,v 1.1 2014/10/19 10:6:56 keckhardt Exp $

BUILDLINK_TREE+=	gcc6snapshot

.if !defined(GCC6_BUILDLINK3_MK)
GCC6SNAPSHOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc6snapshot+=	gcc6>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc6snapshot+=	gcc6>=6.0
BUILDLINK_PKGSRCDIR.gcc6snapshot=	../../wip/gcc6snapshot
BUILDLINK_DEPMETHOD.gcc6snapshot?=	build

BUILDLINK_FILES.gcc6snapshot=		#empty
BUILDLINK_AUTO_VARS.gcc6snapshot=	no

# Packages that link against shared libraries need a full dependency.
#.if defined(_USE_GCC_SHLIB)
#DEPENDS+=	{gcc6, gcc6-libs}>=${_GCC_REQD}:../../lang/gcc6-libs
#ABI_DEPENDS+=	{gcc6,gcc6-libs}>=6.0:../../lang/gcc6-libs
#.endif

pkgbase := gcc6snapshot
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc6snapshot:Mgcc-java)
.include "../../devel/zlib/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC6SNAPSHOT_BUILDLINK3_MK
BUILDLINK_TREE+=	-gcc6snapshot
