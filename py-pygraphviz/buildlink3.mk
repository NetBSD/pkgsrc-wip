# $NetBSD: buildlink3.mk,v 1.2 2015/04/14 11:33:02 thomasklausner Exp $

BUILDLINK_TREE+=	py-pygraphviz

.if !defined(PY_PYGRAPHVIZ_BUILDLINK3_MK)
PY_PYGRAPHVIZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-pygraphviz+=	${PYPKGPREFIX}-pygraphviz>=1.0
BUILDLINK_PKGSRCDIR.py-pygraphviz?=	../../wip/py-pygraphviz

.endif	# PY_PYGRAPHVIZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pygraphviz
