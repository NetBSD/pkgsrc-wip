# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/03/06 07:20:11 jeremy-c-reed Exp $
#
# This file was created automatically using createbuildlink-3.2.

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GETTEXT_RUNTIME_BUILDLINK3_MK:=	${GETTEXT_RUNTIME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gettext-runtime
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngettext-runtime}
BUILDLINK_PACKAGES+=	gettext-runtime

.if !empty(GETTEXT_RUNTIME_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gettext-runtime+=	gettext-runtime>=0.14.1
BUILDLINK_PKGSRCDIR.gettext-runtime?=	../../devel/gettext-runtime

.endif	# GETTEXT_RUNTIME_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
