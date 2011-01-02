# $NetBSD: buildlink3.mk,v 1.1 2011/01/02 21:21:00 helgoman Exp $

BUILDLINK_TREE+=	py26-logilab-astng

.if !defined(PY26_LOGILAB_ASTNG_BUILDLINK3_MK)
PY26_LOGILAB_ASTNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py26-logilab-astng+=	py26-logilab-astng>=0.21.0
BUILDLINK_PKGSRCDIR.py26-logilab-astng?=	../../wip/py-logilab-astng

#.include "../../wip/py-logilab-common/buildlink3.mk"
.endif	# PY26_LOGILAB_ASTNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-py26-logilab-astng
