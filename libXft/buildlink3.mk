# $NetBSD: buildlink3.mk,v 1.2 2006/10/13 12:22:58 jeremy-c-reed Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBXFT_BUILDLINK3_MK:=	${LIBXFT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=		libXft
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:NlibXft}
BUILDLINK_PACKAGES+=	libXft

.if !empty(LIBXFT_BUILDLINK3_MK:M+)
BUILDLINK_ABI_DEPENDS.libXft+=	libXft>=2.1
BUILDLINK_API_DEPENDS.libXft+=	libXft>=2.1.7nb2
BUILDLINK_PKGSRCDIR.libXft?=	../../wip/libXft
.endif	# LIBXFT_BUILDLINK3_MK

.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../wip/libXrender/buildlink3.mk"

.if defined(X11_TYPE) && ${X11_TYPE} == "native"
CONFIGURE_ENV+=	XFT_CFLAGS="-I${PREFIX}/include -I/${PREFIX}/include/freetype2"
CONFIGURE_ENV+=	XFT_LIBS="-L${PREFIX}/lib -lXft"
.endif

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
