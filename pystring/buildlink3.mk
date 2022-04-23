# $NetBSD$

BUILDLINK_TREE+=	pystring

.if !defined(PYSTRING_BUILDLINK3_MK)
PYSTRING_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pystring+=	pystring>=1.1.3
BUILDLINK_PKGSRCDIR.pystring?=		../../wip/pystring
.endif	# PYSTRING_BUILDLINK3_MK

BUILDLINK_TREE+=	-pystring
