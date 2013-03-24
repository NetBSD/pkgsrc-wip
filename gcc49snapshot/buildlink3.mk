# $NetBSD: buildlink3.mk,v 1.1 2013/03/24 10:15:20 keckhardt Exp $

BUILDLINK_TREE+=	gcc49snapshot

.if !defined(GCC49_BUILDLINK3_MK)
GCC49SNAPSHOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc49snapshot+=	gcc49>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc49snapshot+=	gcc49>=4.9.0
BUILDLINK_PKGSRCDIR.gcc49snapshot=	../../wip/gcc49snapshot
BUILDLINK_DEPMETHOD.gcc49snapshot?=	build

FIND_PREFIX:=	BUILDLINK_PREFIX.gcc49snapshot=gcc49snapshot
.include "../../mk/find-prefix.mk"
BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc49snapshot}/gcc49snapshot

BUILDLINK_FILES.gcc49snapshot=		#empty
BUILDLINK_AUTO_VARS.gcc49snapshot=	no

# Packages that link against shared libraries need a full dependency.
#.if defined(_USE_GCC_SHLIB)
#DEPENDS+=	{gcc49, gcc49-libs}>=${_GCC_REQD}:../../lang/gcc49-libs
#ABI_DEPENDS+=	{gcc49,gcc49-libs}>=4.9.0:../../lang/gcc49-libs
#.endif

pkgbase := gcc49snapshot
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc49snapshot:Mgcc-java)
.include "../../devel/zlib/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC49SNAPSHOT_BUILDLINK3_MK
BUILDLINK_TREE+=	-gcc49snapshot
