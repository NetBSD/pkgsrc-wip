# $NetBSD: buildlink3.mk,v 1.19 2024/11/17 07:16:36 wiz Exp $

BUILDLINK_TREE+=	gcr4

.if !defined(GCR4_BUILDLINK3_MK)
GCR4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcr4+=	gcr4>=4.3.0
BUILDLINK_ABI_DEPENDS.gcr4+=	gcr4>=4.3.0
BUILDLINK_PKGSRCDIR.gcr4?=	../../wip/gcr4

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/p11-kit/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.endif	# GCR4_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcr4
