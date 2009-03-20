# $NetBSD: buildlink3.mk,v 1.4 2009/03/20 19:43:41 jsonn Exp $

BUILDLINK_TREE+=	esdl

BUILDLINK_API_DEPENDS.esdl+=	esdl>=0.95
BUILDLINK_ABI_DEPENDS.esdl?=	esdl>=0.95.0630nb1
BUILDLINK_PKGSRCDIR.esdl?=	../../wip/esdl

.include "../../lang/erlang/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.endif # ESDL_BUILDLINK3_MK

BUILDLINK_TREE+=	-esdl
