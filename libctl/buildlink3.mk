# $NetBSD: buildlink3.mk,v 1.2 2012/03/22 21:21:32 outpaddling Exp $

BUILDLINK_TREE+=	libctl

.if !defined(LIBCTL_BUILDLINK3_MK)
LIBCTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libctl+=	libctl>=3.1
BUILDLINK_PKGSRCDIR.libctl?=	../../wip/libctl

# CONFIGURE_ARGS+=	--with-libctl=${PREFIX}

.include "../../lang/guile/buildlink3.mk"
.endif	# LIBCTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libctl
