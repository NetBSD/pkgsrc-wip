# $NetBSD: buildlink3.mk,v 1.1 2014/10/19 10:50:56 keckhardt Exp $

BUILDLINK_TREE+=	gcc50snapshot

.if !defined(GCC50_BUILDLINK3_MK)
GCC50SNAPSHOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc50snapshot+=	gcc50>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc50snapshot+=	gcc50>=5.0
BUILDLINK_PKGSRCDIR.gcc50snapshot=	../../wip/gcc50snapshot
BUILDLINK_DEPMETHOD.gcc50snapshot?=	build

FIND_PREFIX:=	BUILDLINK_PREFIX.gcc50snapshot=gcc50snapshot
.include "../../mk/find-prefix.mk"
BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc50snapshot}/gcc50snapshot

BUILDLINK_FILES.gcc50snapshot=		#empty
BUILDLINK_AUTO_VARS.gcc50snapshot=	no

# Packages that link against shared libraries need a full dependency.
#.if defined(_USE_GCC_SHLIB)
#DEPENDS+=	{gcc50, gcc50-libs}>=${_GCC_REQD}:../../lang/gcc50-libs
#ABI_DEPENDS+=	{gcc50,gcc50-libs}>=4.10.0:../../lang/gcc50-libs
#.endif

pkgbase := gcc50snapshot
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc50snapshot:Mgcc-java)
.include "../../devel/zlib/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC50SNAPSHOT_BUILDLINK3_MK
BUILDLINK_TREE+=	-gcc50snapshot
