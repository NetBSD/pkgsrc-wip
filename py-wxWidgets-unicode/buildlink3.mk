# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/10/03 15:18:35 milosn Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
PY_WXWIDGETS_UNICODE_BUILDLINK3_MK:=	${PY_WXWIDGETS_UNICODE_BUILDLINK3_MK}+

.include "../../lang/python/pyversion.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	${PYPKGPREFIX}-wxWidgets-unicode
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:N${PYPKGPREFIX}-wxWidgets-unicode}
BUILDLINK_PACKAGES+=	${PYPKGPREFIX}-wxWidgets
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}${PYPKGPREFIX}-wxWidgets-unicode

.if !empty(PY_WXWIDGETS_UNICODE_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-wxWidgets-unicode+=	${PYPKGPREFIX}-wxWidgets-unicode>=2.6.3.3
BUILDLINK_ABI_DEPENDS.${PYPKGPREFIX}-wxWidgets-unicode?=	${PYPKGPREFIX}-wxWidgets-unicode>=2.6.3.3
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-wxWidgets-unicode?=		../../wip/py-wxWidgets-unicode

.include "../../wip/wxGTK-unicode/buildlink3.mk"

.endif	# PY_WXWIDGETS_UNICODE_BUILDLINK3_MK

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
