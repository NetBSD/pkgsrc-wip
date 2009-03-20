# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:40 jsonn Exp $

BUILDLINK_TREE+=	ecl

.if !defined(ECL_BUILDLINK3_MK)
ECL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ecl+=	ecl>=0.9.12
BUILDLINK_PKGSRCDIR.ecl?=	../../wip/ecl

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.endif # ECL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ecl
