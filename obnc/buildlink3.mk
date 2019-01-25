# $NetBSD$

BUILDLINK_TREE+=	obnc

.if !defined(OBNC_BUILDLINK3_MK)
OBNC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.obnc+=	obnc>=0.14.2
BUILDLINK_PKGSRCDIR.obnc?=	../../wip/obnc

#BUILDLINK_DEPMETHOD.obnc?=	build

#.include "../../devel/boehm-gc/buildlink3.mk"
.endif	# OBNC_BUILDLINK3_MK

BUILDLINK_TREE+=	-obnc
