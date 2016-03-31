# $NetBSD$

BUILDLINK_TREE+=	erlang-basho

.if !defined(ERLANG_BASHO_BUILDLINK3_MK)
ERLANG_BASHO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.erlang-basho+=	erlang-basho>=16
BUILDLINK_PKGSRCDIR.erlang-basho?=	../../wip/erlang-basho

.endif # ERLANG_BASHO_BUILDLINK3_MK

BUILDLINK_TREE+=	-erlang-basho
