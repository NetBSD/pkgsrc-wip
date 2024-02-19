# $NetBSD$

BUILDLINK_TREE+=	py-sip4

.if !defined(PY_SIP_BUILDLINK3_MK)
PY_SIP_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-sip4+=	${PYPKGPREFIX}-sip4>=4.14.7<5
BUILDLINK_PKGSRCDIR.py-sip4?=	../../wip/py-sip4
.endif # PY_SIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-sip4
