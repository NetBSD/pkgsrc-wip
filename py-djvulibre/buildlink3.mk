# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/07/31 08:08:46 ryo-on Exp $

BUILDLINK_TREE+=	py-djvulibre

.if !defined(PY_DJVULIBRE_BUILDLINK3_MK)
PY_DJVULIBRE_BUILDLINK3_MK:=

.  include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-djvulibre+=	${PYPKGPREFIX}-djvulibre>=0.1.17
BUILDLINK_PKGSRCDIR.py-djvulibre?=	../../local/py-djvulibre

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.endif	# PY_DJVULIBRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-djvulibre
