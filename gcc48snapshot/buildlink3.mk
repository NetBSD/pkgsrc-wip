# $NetBSD: buildlink3.mk,v 1.1 2013/02/23 10:04:11 keckhardt Exp $

BUILDLINK_TREE+=	gcc48snapshot

.if !defined(GCC48_BUILDLINK3_MK)
GCC48SNAPSHOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc48snapshot+=	gcc48>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc48snapshot+=	gcc48>=4.8.0
BUILDLINK_PKGSRCDIR.gcc48snapshot=	../../wip/gcc48snapshot
BUILDLINK_DEPMETHOD.gcc48snapshot?=	build

FIND_PREFIX:=	BUILDLINK_PREFIX.gcc48snapshot=gcc48snapshot
.include "../../mk/find-prefix.mk"
BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc48snapshot}/gcc48snapshot

BUILDLINK_FILES.gcc48snapshot=		#empty
BUILDLINK_AUTO_VARS.gcc48snapshot=	no

# Packages that link against shared libraries need a full dependency.
#.if defined(_USE_GCC_SHLIB)
#DEPENDS+=	{gcc48, gcc48-libs}>=${_GCC_REQD}:../../lang/gcc48-libs
#ABI_DEPENDS+=	{gcc48,gcc48-libs}>=4.8.0:../../lang/gcc48-libs
#.endif

pkgbase := gcc48snapshot
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc48snapshot:Mgcc-java)
.include "../../devel/zlib/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC48SNAPSHOT_BUILDLINK3_MK
BUILDLINK_TREE+=	-gcc48snapshot
