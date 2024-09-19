# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:43:48 jsonn Exp $

BUILDLINK_TREE+=	libglade-java

BUILDLINK_API_DEPENDS.libglade-java+=	libglade-java>=2.10.1
BUILDLINK_PKGSRCDIR.libglade-java?=	../../wip/libglade-java
.endif # LIBGLADE_JAVA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libglade-java
