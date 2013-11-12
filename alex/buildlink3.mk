# $NetBSD: buildlink3.mk,v 1.4 2013/11/12 10:03:28 szptvlfn Exp $

BUILDLINK_TREE+=	alex

.if !defined(ALEX_BUILDLINK3_MK)
ALEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alex+=	alex>=3.1.2
BUILDLINK_PKGSRCDIR.alex?=	../../wip/alex

.include "../../wip/hs-QuickCheck/buildlink3.mk"
.endif	# ALEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-alex
