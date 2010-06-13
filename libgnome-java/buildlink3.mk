# $NetBSD: buildlink3.mk,v 1.5 2010/06/13 22:47:10 thomasklausner Exp $

BUILDLINK_TREE+=	libgnome-java

.if !defined(LIBGNOME_JAVA_BUILDLINK3_MK)
LIBGNOME_JAVA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnome-java+=	libgnome-java>=2.10.1
BUILDLINK_ABI_DEPENDS.libgnome-java?=	libgnome-java>=2.10.1nb4
BUILDLINK_PKGSRCDIR.libgnome-java?=	../../wip/libgnome-java

.include "../../wip/libgtk-java/buildlink3.mk"
.endif # LIBGNOME_JAVA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnome-java
