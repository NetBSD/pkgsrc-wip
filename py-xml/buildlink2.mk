# $NetBSD: buildlink2.mk,v 1.1 2004/01/04 11:35:48 mpasternak Exp $
#
# This Makefile fragment is included by packages that use py-xml.
#

.if !defined(PY_XML_BUILDLINK2_MK)
PY_XML_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			${PYPKGPREFIX}-xml
BUILDLINK_DEPENDS.${PYPKGPREFIX}-xml?=		${PYPKGPREFIX}-xml>=0.8.3
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-xml?=		../../wip/py-xml

EVAL_PREFIX+=	BUILDLINK_PREFIX.${PYPKGPREFIX}-xml=${PYPKGPREFIX}-xml
BUILDLINK_PREFIX.${PYPKGPREFIX}-xml_DEFAULT=	${LOCALBASE}

BUILDLINK_TARGETS+=	${PYPKGPREFIX}-xml-buildlink

${PYPKGPREFIX}-xml-buildlink: _BUILDLINK_USE

.endif	# PY_XML_BUILDLINK2_MK
