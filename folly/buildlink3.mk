# $NetBSD$

BUILDLINK_TREE+=	folly

.if !defined(FOLLY_BUILDLINK3_MK)
FOLLY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.folly+=	folly>=2023.11.20.00
BUILDLINK_PKGSRCDIR.folly?=	../../wip/folly

#.include "../../archivers/lz4/buildlink3.mk"
#.include "../../archivers/zstd/buildlink3.mk"
#.include "../../devel/boost-libs/buildlink3.mk"
#.include "../../devel/gflags/buildlink3.mk"
#.include "../../devel/google-glog/buildlink3.mk"
#.include "../../math/double-conversion/buildlink3.mk"
#.include "../../textproc/fmtlib/buildlink3.mk"
.endif	# FOLLY_BUILDLINK3_MK

BUILDLINK_TREE+=	-folly
