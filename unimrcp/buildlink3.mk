# $NetBSD$

BUILDLINK_TREE+=	unimrcp

.if !defined(UNIMRCP_BUILDLINK3_MK)
UNIMRCP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.unimrcp+=	unimrcp>=1.4.0
BUILDLINK_ABI_DEPENDS.unimrcp+=	unimrcp>=1.4.0
BUILDLINK_PKGSRCDIR.unimrcp?=	../../wip/unimrcp

#.include "../../wip/unimrcp-sofiasip/buildlink3.mk"
#.include "../../wip/unimrcp-apr/buildlink3.mk"
#.include "../../wip/unimrcp-aprutil/buildlink3.mk"
.endif	# UNIMRCP_BUILDLINK3_MK

BUILDLINK_TREE+=	-unimrcp
