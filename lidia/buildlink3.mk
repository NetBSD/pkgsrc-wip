# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:47:33 cheusov Exp $

BUILDLINK_TREE+=	LiDIA

.if !defined(LIDIA_BUILDLINK3_MK)
LIDIA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.LiDIA+=	LiDIA>=2.1.3
BUILDLINK_PKGSRCDIR.LiDIA?=	../../wip/lidia

.include "../../devel/gmp/buildlink3.mk"
.endif # LIDIA_BUILDLINK3_MK

BUILDLINK_TREE+=	-LiDIA
