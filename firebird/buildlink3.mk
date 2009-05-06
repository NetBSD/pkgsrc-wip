# $NetBSD: buildlink3.mk,v 1.5 2009/05/06 10:47:32 cheusov Exp $

BUILDLINK_TREE+=	firebird

.if !defined(FIREBIRD_BUILDLINK3_MK)
FIREBIRD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.firebird+=	firebird>=2.0.0.12710rc3
BUILDLINK_PKGSRCDIR.firebird?=		../../wip/firebird
.endif # FIREBIRD_BUILDLINK3_MK

BUILDLINK_TREE+=	-firebird
