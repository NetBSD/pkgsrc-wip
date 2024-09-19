# $NetBSD$

BUILDLINK_TREE+=	gcc9snapshot

.if !defined(GCC9SNAPSHOT_BUILDLINK3_MK)
GCC9SNAPSHOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc9snapshot+=	gcc9>=9.0
BUILDLINK_ABI_DEPENDS.gcc9snapshot+=	gcc9>=9.0
BUILDLINK_PKGSRCDIR.gcc9snapshot=	../../wip/gcc9snapshot
BUILDLINK_DEPMETHOD.gcc9snapshot?=	build

BUILDLINK_FILES.gcc9snapshot=		# none
BUILDLINK_AUTO_VARS.gcc9snapshot=	no

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC9SNAPSHOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc9snapshot
