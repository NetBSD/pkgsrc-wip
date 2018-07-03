# $NetBSD: buildlink3.mk,v 1.2 2015/04/14 11:33:02 thomasklausner Exp $

BUILDLINK_TREE+=	py-gsl

.if !defined(PY_GSL_BUILDLINK3_MK)
PY_GSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-gsl+=	${PYPKGPREFIX}-gsl>=0.9.5
BUILDLINK_PKGSRCDIR.py-gsl?=	../../wip/py-gsl

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-Numeric, py-numarray via py-gsl
.include "../../math/gsl/buildlink3.mk"
#.include "../../math/py-numpy/buildlink3.mk"
.endif	# PY_GSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gsl
