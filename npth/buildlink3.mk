# $NetBSD: buildlink3.mk,v 1.1 2015/03/20 15:09:57 adanbsd Exp $
# XXX	BUILDLINK_DEPMETHOD.npth?=	build

BUILDLINK_TREE+=	npth

.if !defined(NPTH_BUILDLINK3_MK)
NPTH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.npth+=	npth>=1.1
BUILDLINK_PKGSRCDIR.npth?=	../../wip/npth
.endif	# NPTH_BUILDLINK3_MK

BUILDLINK_TREE+=	-npth
