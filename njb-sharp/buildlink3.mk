# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/04/24 23:48:46 jihbed Exp $

BUILDLINK_TREE+=	njb-sharp

.if !defined(NJB_SHARP_BUILDLINK3_MK)
NJB_SHARP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.njb-sharp+=	njb-sharp>=0.2.2
BUILDLINK_PKGSRCDIR.njb-sharp?=		../../wip/njb-sharp


.include "../../wip/libnjb/buildlink3.mk"
.endif	#NJB_SHARP_BUILDLINK3_MK

BUILDLINK_TREE+=	-njb-sharp
