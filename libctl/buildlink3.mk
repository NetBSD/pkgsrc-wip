# $NetBSD: buildlink3.mk,v 1.1.1.1 2012/03/22 21:16:11 outpaddling Exp $

BUILDLINK_TREE+=	libctl

.if !defined(LIBCTL_BUILDLINK3_MK)
LIBCTL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libctl+=	libctl>=3.1
BUILDLINK_PKGSRCDIR.libctl?=	../../jb-wip/libctl

# CONFIGURE_ARGS+=	--with-libctl=${PREFIX}

.include "../../lang/guile/buildlink3.mk"
.endif	# LIBCTL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libctl
