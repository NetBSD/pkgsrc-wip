# $NetBSD$

BUILDLINK_TREE+=	libyang

.if !defined(LIBYANG_BUILDLINK3_MK)
LIBYANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libyang+=	libyang>=1.0.184
BUILDLINK_PKGSRCDIR.libyang?=	../../wip/libyang

.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/cmocka/buildlink3.mk"

.endif	# LIBYANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libyang
