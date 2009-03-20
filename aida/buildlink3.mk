# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:43:39 jsonn Exp $

BUILDLINK_TREE+=	aida

.if !defined(AIDA_BUILDLINK3_MK)
AIDA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.aida+=	aida>=3.2.1
BUILDLINK_PKGSRCDIR.aida?=	../../wip/aida
BUILDLINK_DEPMETHOD.aida?=	build
.endif # AIDA_BUILDLINK3_MK

BUILDLINK_TREE+=	-aida
