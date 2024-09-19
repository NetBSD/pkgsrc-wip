# $NetBSD$

BUILDLINK_TREE+=	gcc10snapshot

.if !defined(GCC10SNAPSHOT_BUILDLINK3_MK)
GCC10SNAPSHOT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc10snapshot+=	gcc10>=10.0
BUILDLINK_ABI_DEPENDS.gcc10snapshot+=	gcc10>=10.0
BUILDLINK_PKGSRCDIR.gcc10snapshot=	../../wip/gcc10snapshot
BUILDLINK_DEPMETHOD.gcc10snapshot?=	build

BUILDLINK_FILES.gcc10snapshot=		# none
BUILDLINK_AUTO_VARS.gcc10snapshot=	no

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GCC10SNAPSHOT_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcc10snapshot
