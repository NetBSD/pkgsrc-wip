# $NetBSD$

BUILDLINK_TREE+=	libkiwix

.if !defined(LIBKIWIX_BUILDLINK3_MK)
LIBKIWIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkiwix+=	libkiwix>=14.0.0
BUILDLINK_PKGSRCDIR.libkiwix?=		../../wip/libkiwix

#.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
#.include "../../textproc/xapian/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
#.include "../../wip/libzim/buildlink3.mk"
#.include "../../wip/mustache/buildlink3.mk"
.endif	# LIBKIWIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkiwix
