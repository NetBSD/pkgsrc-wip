# $NetBSD$

BUILDLINK_TREE+=	or-tools

.if !defined(OR_TOOLS_BUILDLINK3_MK)
OR_TOOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.or-tools+=	or-tools>=99bugfix
BUILDLINK_PKGSRCDIR.or-tools?=		../../wip/or-tools

.include "../../wip/HiGHS/buildlink3.mk"
.include "../../wip/scip/buildlink3.mk"
.include "../../wip/ThirdParty-Mumps/buildlink3.mk"
.include "../../wip/nauty/buildlink3.mk"
.include "../../wip/ThirdParty-ASL/buildlink3.mk"
.include "../../devel/abseil/buildlink3.mk"
.include "../../math/openblas/buildlink3.mk"
.include "../../math/coinmp/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../devel/googletest/buildlink3.mk"
.include "../../devel/gflags/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/re2/buildlink3.mk"
.include "../../devel/google-glog/buildlink3.mk"
.endif	# OR_TOOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-or-tools
