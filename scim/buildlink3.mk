# $NetBSD: buildlink3.mk,v 1.4 2006/09/18 18:20:42 dhowland Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SCIM_BUILDLINK3_MK:=	${SCIM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	scim
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nscim}
BUILDLINK_PACKAGES+=	scim

.if !empty(SCIM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.scim+=	scim>=1.4.4
BUILDLINK_PKGSRCDIR.scim?=	../../wip/scim
.endif	# SCIM_BUILDLINK3_MK

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
