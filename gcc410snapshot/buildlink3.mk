# $NetBSD: buildlink3.mk,v 1.1 2014/04/29 14:14:34 keckhardt Exp $

BUILDLINK_TREE+=	gcc410snapshot

.if !defined(GCC410_BUILDLINK3_MK)
GCC410SNAPSHOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc410snapshot+=	gcc410>=${_GCC_REQD}
BUILDLINK_ABI_DEPENDS.gcc410snapshot+=	gcc410>=4.10.0
BUILDLINK_PKGSRCDIR.gcc410snapshot=	../../wip/gcc410snapshot
BUILDLINK_DEPMETHOD.gcc410snapshot?=	build

FIND_PREFIX:=	BUILDLINK_PREFIX.gcc410snapshot=gcc410snapshot
.include "../../mk/find-prefix.mk"
BUILDLINK_PASSTHRU_DIRS+=	${BUILDLINK_PREFIX.gcc410snapshot}/gcc410snapshot

BUILDLINK_FILES.gcc410snapshot=		#empty
BUILDLINK_AUTO_VARS.gcc410snapshot=	no

# Packages that link against shared libraries need a full dependency.
#.if defined(_USE_GCC_SHLIB)
#DEPENDS+=	{gcc410, gcc410-libs}>=${_GCC_REQD}:../../lang/gcc410-libs
#ABI_DEPENDS+=	{gcc410,gcc410-libs}>=4.10.0:../../lang/gcc410-libs
#.endif

pkgbase := gcc410snapshot
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.gcc410snapshot:Mgcc-java)
.include "../../devel/zlib/buildlink3.mk"
.endif

.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC410SNAPSHOT_BUILDLINK3_MK
BUILDLINK_TREE+=	-gcc410snapshot
