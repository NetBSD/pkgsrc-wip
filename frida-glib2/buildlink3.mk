# $NetBSD$

BUILDLINK_TREE+=	frida-glib2

.if !defined(FRIDA_GLIB2_BUILDLINK3_MK)
FRIDA_GLIB2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.frida-glib2+=	frida-glib2>=2.54.3
BUILDLINK_PKGSRCDIR.frida-glib2?=	../../wip/frida-glib2

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libffi/buildlink3.mk"
.endif	# FRIDA_GLIB2_BUILDLINK3_MK

BUILDLINK_TREE+=	-frida-glib2
