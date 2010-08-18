# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/08/18 11:55:35 jihbed Exp $

BUILDLINK_TREE+=	py26-gsl

.if !defined(PY26_GSL_BUILDLINK3_MK)
PY26_GSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-gsl+=	py26-gsl>=0.9.5
BUILDLINK_PKGSRCDIR.py26-gsl?=	../../wip/py-gsl

.include "../../math/gsl/buildlink3.mk"
#.include "../../math/py-numpy/buildlink3.mk"
.endif	# PY26_GSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-gsl
