# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:51 jsonn Exp $

BUILDLINK_TREE+=	parsec

.if !defined(PARSEC_BUILDLINK3_MK)
PARSEC_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.parsec?=	build
BUILDLINK_API_DEPENDS.parsec+=	parsec>=3.0.0
BUILDLINK_PKGSRCDIR.parsec?=	../../wip/parsec

.include "../../wip/hs-mtl/buildlink3.mk"
.endif # PARSEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-parsec
