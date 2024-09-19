# $NetBSD: buildlink3.mk,v 1.9 2012/12/04 02:33:35 othyro Exp $

BUILDLINK_TREE+=	glib-java

.if !defined(GLIB_JAVA_BUILDLINK3_MK)
GLIB_JAVA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.glib-java+=	glib-java>=0.2.5
BUILDLINK_PKGSRCDIR.glib-java?=		../../wip/glib-java

.include "../../devel/glib2/buildlink3.mk"

.endif # GLIB_JAVA_BUILDLINK3_MK

BUILDLINK_TREE+=	-glib-java
