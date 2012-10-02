# $NetBSD: buildlink3.mk,v 1.1 2012/10/02 19:51:30 othyro Exp $

BUILDLINK_TREE+=	libral

.if !defined(LIBRAL_BUILDLINK3_MK)
LIBRAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libral+=	libral>=0.9.6
BUILDLINK_PKGSRCDIR.libral?=	../../wip/libral

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.endif	# LIBRAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libral
