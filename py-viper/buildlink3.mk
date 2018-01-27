# $NetBSD: buildlink3.mk,v 1.5 2013/03/23 15:03:23 outpaddling Exp $

BUILDLINK_TREE+=	py-viper

.if !defined(PY_VIPER_BUILDLINK3_MK)
PY_VIPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-viper+=	${PYPKGPREFIX}-viper>=1.0.0
BUILDLINK_PKGSRCDIR.py-viper?=		../../wip/py-viper
.endif	# PY_VIPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-viper
