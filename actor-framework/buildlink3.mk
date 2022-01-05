# $NetBSD$

BUILDLINK_TREE+=	actor-framework

.if !defined(ACTOR_FRAMEWORK_BUILDLINK3_MK)
ACTOR_FRAMEWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.actor-framework+=	actor-framework>=0.18.5
BUILDLINK_PKGSRCDIR.actor-framework?=	../../wip/actor-framework

.include "../../security/openssl/buildlink3.mk"
.endif	# ACTOR_FRAMEWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-actor-framework
