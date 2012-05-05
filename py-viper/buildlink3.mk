# $NetBSD: buildlink3.mk,v 1.2 2012/05/05 14:49:34 noud4 Exp $

BUILDLINK_TREE+=	py26-viper

.if !defined(PY26_VIPER_BUILDLINK3_MK)
PY26_VIPER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-viper+=	py26-viper>=1.0.0
BUILDLINK_PKGSRCDIR.py26-viper?=	../../wip/py-viper
.endif	# PY26_VIPER_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-viper
