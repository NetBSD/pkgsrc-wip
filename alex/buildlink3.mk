# $NetBSD: buildlink3.mk,v 1.5 2013/11/28 13:21:51 szptvlfn Exp $

BUILDLINK_TREE+=	alex

.if !defined(ALEX_BUILDLINK3_MK)
ALEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alex+=	alex>=3.1.3
BUILDLINK_PKGSRCDIR.alex?=	../../wip/alex

.include "../../wip/hs-QuickCheck/buildlink3.mk"
.endif	# ALEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-alex
