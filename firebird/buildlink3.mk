# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:41 jsonn Exp $

BUILDLINK_TREE+=	firebird

BUILDLINK_API_DEPENDS.firebird+=	firebird>=2.0.0.12710rc3
BUILDLINK_PKGSRCDIR.firebird?=		../../wip/firebird
.endif # FIREBIRD_BUILDLINK3_MK

BUILDLINK_TREE+=	-firebird
