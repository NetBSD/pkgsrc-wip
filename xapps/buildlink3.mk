# $NetBSD$

BUILDLINK_TREE+=	xapps

.if !defined(XAPPS_BUILDLINK3_MK)
XAPPS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xapps+=	xapps>=1.2.1
BUILDLINK_PKGSRCDIR.xapps?=	../../wip/xapps

.include "../../x11/libxkbfile/buildlink3.mk"
.endif	# XAPPS_BUILDLINK3_MK

BUILDLINK_TREE+=	-xapps
