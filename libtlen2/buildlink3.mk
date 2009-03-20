# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:49 jsonn Exp $

BUILDLINK_TREE+=	libtlen2

BUILDLINK_API_DEPENDS.libtlen2+=	libtlen2>=20040301
BUILDLINK_PKGSRCDIR.libtlen2?=	../../wip/libtlen2

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBTLEN2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtlen2
