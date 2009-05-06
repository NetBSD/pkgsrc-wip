# $NetBSD: buildlink3.mk,v 1.4 2009/05/06 10:01:04 cheusov Exp $

BUILDLINK_TREE+=	libgnome-java

.if !defined(LIBGNOME_JAVA_BUILDLINK3_MK)
LIBGNOME_JAVA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnome-java+=	libgnome-java>=2.10.1
BUILDLINK_PKGSRCDIR.libgnome-java?=	../../wip/libgnome-java

.include "../../wip/libgtk-java/buildlink3.mk"
.endif # LIBGNOME_JAVA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnome-java
