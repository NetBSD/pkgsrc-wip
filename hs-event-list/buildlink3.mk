# $NetBSD: buildlink3.mk,v 1.2 2010/02/19 08:20:55 phonohawk Exp $

BUILDLINK_TREE+=	hs-event-list

.if !defined(HS_EVENT_LIST_BUILDLINK3_MK)
HS_EVENT_LIST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-event-list+=	hs-event-list>=0.0.10.1
BUILDLINK_PKGSRCDIR.hs-event-list?=	../../wip/hs-event-list

.include "../../wip/hs-non-negative/buildlink3.mk"
.include "../../wip/hs-transformers/buildlink3.mk"
.include "../../wip/hs-utility-ht/buildlink3.mk"
.endif	# HS_EVENT_LIST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-event-list
