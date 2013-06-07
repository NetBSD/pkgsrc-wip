# $NetBSD: buildlink3.mk,v 1.1 2013/06/07 20:12:14 othyro Exp $

BUILDLINK_TREE+=	py27-cjson

.if !defined(PY27_CJSON_BUILDLINK3_MK)
PY27_CJSON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py27-cjson+=	py27-cjson>=1.0.5
BUILDLINK_PKGSRCDIR.py27-cjson?=	../../wip/py-cjson
.endif	# PY27_CJSON_BUILDLINK3_MK

BUILDLINK_TREE+=	-py27-cjson
