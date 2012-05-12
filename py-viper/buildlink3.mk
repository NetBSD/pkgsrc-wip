# $NetBSD: buildlink3.mk,v 1.4 2012/05/12 14:33:39 outpaddling Exp $

BUILDLINK_TREE+=	viper

.if !defined(PY_VIPER_BUILDLINK3_MK)
PY_VIPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.viper+=	${PYPKGPREFIX}-viper>=1.0.0
BUILDLINK_PKGSRCDIR.viper?=	../../wip/py-viper
.endif	# PY_VIPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-viper
