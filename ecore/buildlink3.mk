# $NetBSD: buildlink3.mk,v 1.21 2012/12/30 19:41:18 roelants Exp $

BUILDLINK_TREE+=	ecore

.if !defined(ECORE_BUILDLINK3_MK)
ECORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ecore+=	ecore>=1.7.0
BUILDLINK_PKGSRCDIR.ecore?=	../../wip/ecore

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../wip/eet/buildlink3.mk"
.include "../../wip/evas/buildlink3.mk"
.include "../../wip/evas-software-x11/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXdamage/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXrender/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.endif # ECORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ecore
