# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:52 jsonn Exp $

.include "../../lang/python/pyversion.mk"

BUILDLINK_TREE+=	${PYPKGPREFIX}-wxWidgets-unicode

.if !defined(PY_WXWIDGETS_UNICODE_BUILDLINK3_MK)
PY_WXWIDGETS_UNICODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.${PYPKGPREFIX}-wxWidgets-unicode+=	${PYPKGPREFIX}-wxWidgets-unicode>=2.6.3.3
BUILDLINK_ABI_DEPENDS.${PYPKGPREFIX}-wxWidgets-unicode?=	${PYPKGPREFIX}-wxWidgets-unicode>=2.6.3.3
BUILDLINK_PKGSRCDIR.${PYPKGPREFIX}-wxWidgets-unicode?=		../../wip/py-wxWidgets-unicode

.include "../../wip/wxGTK-unicode/buildlink3.mk"
.endif # PY_WXWIDGETS_UNICODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-${PYPKGPREFIX}-wxWidgets-unicode
