# $NetBSD: buildlink3.mk,v 1.4 2010/01/18 09:38:30 thomasklausner Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_TREE+=	${PYPKGPREFIX}-wxWidgets-unicode

.if !defined(PY_WXWIDGETS_UNICODE_BUILDLINK3_MK)
PY_WXWIDGETS_UNICODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-wxWidgets-unicode+=	${PYPKGPREFIX}-wxWidgets-unicode>=2.6.3.3
BUILDLINK_ABI_DEPENDS.${PYPKGPREFIX}-wxWidgets-unicode?=	${PYPKGPREFIX}-wxWidgets-unicode>=2.8.8.1nb1
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-wxWidgets-unicode?=		../../wip/py-wxWidgets-unicode

.include "../../wip/wxGTK-unicode/buildlink3.mk"
.endif # PY_WXWIDGETS_UNICODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-${PYPKGPREFIX}-wxWidgets-unicode
