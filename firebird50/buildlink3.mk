# $NetBSD$

BUILDLINK_TREE+=	firebird

.if !defined(FIREBIRD_BUILDLINK3_MK)
FIREBIRD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.firebird+=	firebird>=5.0.4
BUILDLINK_PKGSRCDIR.firebird?=		../../wip/firebird50
.endif # FIREBIRD_BUILDLINK3_MK

BUILDLINK_TREE+=	-firebird
