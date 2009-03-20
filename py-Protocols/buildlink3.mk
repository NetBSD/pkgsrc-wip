# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:51 jsonn Exp $
#
# This Makefile fragment is included by packages that use py-Protocols.
#

.include "../../lang/python/pyversion.mk"

BUILDLINK_TREE+=	${PYPKGPREFIX}-Protocols

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-Protocols+=		${PYPKGPREFIX}-Protocols>=0.9.2
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-Protocols?=		../../wip/py-Protocols
.endif # PY_PROTOCOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-${PYPKGPREFIX}-Protocols
