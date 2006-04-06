# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:17:15 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
ESDL_BUILDLINK3_MK:=		${ESDL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		esdl
.endif

BUILDLINK_PACKAGES:=		${BUILDLINK_PACKAGES:Nesdl}
BUILDLINK_PACKAGES+=		esdl

.if !empty(ESDL_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.esdl+=	esdl>=0.95
BUILDLINK_PKGSRCDIR.esdl?=	../../wip/esdl
.endif	# ESDL_BUILDLINK3_MK

.include "../../lang/erlang/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
