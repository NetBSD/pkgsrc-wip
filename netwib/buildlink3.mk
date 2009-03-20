# $NetBSD: buildlink3.mk,v 1.5 2009/03/20 19:43:51 jsonn Exp $

BUILDLINK_TREE+=	netwib

.if !defined(NETWIB_BUILDLINK3_MK)
NETWIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netwib+=	netwib>=5.35.0
BUILDLINK_PKGSRCDIR.netwib?=	../../wip/netwib

.include "../../devel/libnet10/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.endif # NETWIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-netwib
