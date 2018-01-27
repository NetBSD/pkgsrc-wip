# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:21:03 cheusov Exp $

BUILDLINK_TREE+=	libtlen2

.if !defined(LIBTLEN2_BUILDLINK3_MK)
LIBTLEN2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtlen2+=	libtlen2>=20040301
BUILDLINK_PKGSRCDIR.libtlen2?=		../../wip/libtlen2

.include "../../devel/glib2/buildlink3.mk"
.include "../../net/gnet/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.endif # LIBTLEN2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtlen2
