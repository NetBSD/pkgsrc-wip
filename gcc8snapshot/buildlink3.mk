# $NetBSD: buildlink3.mk,v 1.1 2014/10/19 10:6:56 keckhardt Exp $

BUILDLINK_TREE+=	gcc7snapshot

.if !defined(GCC7_BUILDLINK3_MK)
GCC6SNAPSHOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc7snapshot+=	gcc6>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc7snapshot+=	gcc6>=7.0
BUILDLINK_PKGSRCDIR.gcc7snapshot=	../../wip/gcc7snapshot
BUILDLINK_DEPMETHOD.gcc7snapshot?=	build

BUILDLINK_FILES.gcc7snapshot=		#empty
BUILDLINK_AUTO_VARS.gcc7snapshot=	no

# Packages that link against shared libraries need a full dependency.
#.if defined(_USE_GCC_SHLIB)
#DEPENDS+=	{gcc7, gcc7-libs}>=${_GCC_REQD}:../../lang/gcc7-libs
#ABI_DEPENDS+=	{gcc7,gcc7-libs}>=7.0:../../lang/gcc7-libs
#.endif

pkgbase := gcc7snapshot
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc7snapshot:Mgcc-java)
.include "../../devel/zlib/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC7SNAPSHOT_BUILDLINK3_MK
BUILDLINK_TREE+=	-gcc7snapshot
