# $NetBSD: buildlink3.mk,v 1.2 2006/04/06 07:18:21 jeremy-c-reed Exp $
#
# This Makefile fragment is included by packages that use py-Protocols.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PY_PROTOCOLS_BUILDLINK3_MK:=	${PY_PROTOCOLS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	${PYPKGPREFIX}-Protocols
.endif

.if !empty(PY_PROTOCOLS_BUILDLINK3_MK:M+)

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			${PYPKGPREFIX}-Protocols
BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-Protocols+=		${PYPKGPREFIX}-Protocols>=0.9.2
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-Protocols?=		../../wip/py-Protocols

.endif # PY_PROTOCOLS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
