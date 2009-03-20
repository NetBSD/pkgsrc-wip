# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:49 jsonn Exp $

BUILDLINK_TREE+=	LiDIA

BUILDLINK_API_DEPENDS.LiDIA+=	LiDIA>=2.1.3
BUILDLINK_PKGSRCDIR.LiDIA?=	../../wip/lidia

.include "../../devel/gmp/buildlink3.mk"
.endif # LIDIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-LiDIA
