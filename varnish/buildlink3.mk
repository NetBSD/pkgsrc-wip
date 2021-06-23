# $NetBSD$

BUILDLINK_TREE+=	varnish

.if !defined(VARNISH_BUILDLINK3_MK)
VARNISH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.varnish+=	varnish>=6.6.0
BUILDLINK_PKGSRCDIR.varnish?=	../../wip/varnish

.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"

.endif	# VARNISH_BUILDLINK3_MK

BUILDLINK_TREE+=	-varnish
