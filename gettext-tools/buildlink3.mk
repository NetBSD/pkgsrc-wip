# $NetBSD: buildlink3.mk,v 1.1 2004/03/06 07:55:46 jeremy-c-reed Exp $
#
# This file was created automatically using createbuildlink-3.2.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GETTEXT_TOOLS_BUILDLINK3_MK:=	${GETTEXT_TOOLS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gettext-tools
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngettext-tools}
BUILDLINK_PACKAGES+=	gettext-tools

.if !empty(GETTEXT_TOOLS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gettext-tools+=	gettext-tools>=0.14.1
BUILDLINK_PKGSRCDIR.gettext-tools?=	../../wip/gettext-tools

.include "../../wip/gettext-runtime/buildlink3.mk"

.endif	# GETTEXT_TOOLS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
