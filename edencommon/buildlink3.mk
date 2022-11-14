# $NetBSD$

BUILDLINK_TREE+=	edencommon

.if !defined(EDENCOMMON_BUILDLINK3_MK)
EDENCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.edencommon+=	edencommon>=2022.11.07.00
BUILDLINK_PKGSRCDIR.edencommon?=	../../wip/edencommon

#.include "../../devel/google-glog/buildlink3.mk"
.endif	# EDENCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-edencommon
