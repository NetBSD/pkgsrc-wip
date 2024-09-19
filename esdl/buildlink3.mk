# $NetBSD: buildlink3.mk,v 1.5 2009/05/06 10:22:08 cheusov Exp $

BUILDLINK_TREE+=	esdl

.if !defined(ESDL_BUILDLINK3_MK)
ESDL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.esdl+=	esdl>=0.95
BUILDLINK_ABI_DEPENDS.esdl?=	esdl>=0.95.0630nb1
BUILDLINK_PKGSRCDIR.esdl?=	../../wip/esdl

.include "../../lang/erlang/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.endif # ESDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-esdl
