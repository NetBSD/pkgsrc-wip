# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/01/22 20:00:30 oherrala Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
SILC_TOOLKIT_BUILDLINK3_MK:=	${SILC_TOOLKIT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	silc-toolkit
.endif

.if !empty(SILC_TOOLKIT_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			silc-toolkit
BUILDLINK_DEPENDS.silc-toolkit?=	silc-toolkit>=0.9.11
BUILDLINK_PKGSRCDIR.silc-toolkit?=	../../wip/silc-toolkit

.include "../../converters/libiconv/buildlink3.mk"

.endif # SILC_TOOLKIT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
