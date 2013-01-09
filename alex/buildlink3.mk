# $NetBSD: buildlink3.mk,v 1.2 2013/01/09 23:35:34 szptvlfn Exp $

BUILDLINK_TREE+=	alex

.if !defined(ALEX_BUILDLINK3_MK)
ALEX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.alex+=	alex>=3.0
BUILDLINK_PKGSRCDIR.alex?=	../../wip/alex
.endif	# ALEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-alex
