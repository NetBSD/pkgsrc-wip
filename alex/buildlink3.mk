# $NetBSD: buildlink3.mk,v 1.1 2012/03/11 07:23:34 phonohawk Exp $

BUILDLINK_TREE+=	alex

.if !defined(ALEX_BUILDLINK3_MK)
ALEX_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.alex?=	build
BUILDLINK_API_DEPENDS.alex+=	alex>=3.0
BUILDLINK_PKGSRCDIR.alex?=	../../wip/alex
.endif	# ALEX_BUILDLINK3_MK

BUILDLINK_TREE+=	-alex
