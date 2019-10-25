# $NetBSD$

BUILDLINK_TREE+=	gnunet

.if !defined(GNUNET_BUILDLINK3_MK)
GNUNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnunet+=	gnunet>=0.11.0
BUILDLINK_PKGSRCDIR.gnunet?=	../../wip/gnunet

pkgbase:= gnunet
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_OPTIONS:Mopus)
.include "../../audio/libopus/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Msqlite3)
.include "../../databases/sqlite3/buildlink3.mk"
.endif
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libextractor/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.if !empty(PKG_OPTIONS:Midn)
.include "../../devel/libidn2/buildlink3.mk"
.else
.include "../../devel/libidn/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Mtests)
.include "../../lang/python/tool.mk"
.endif
.if !empty(PKG_OPTIONS:Mgstreamer)
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.endif
.if !empty(PKG_OPTIONS:Mogg)
.include "../../multimedia/libogg/buildlink3.mk"
.endif
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.if !empty(PKG_OPTIONS:Mjson)
.include "../../textproc/jansson/buildlink3.mk"
.endif
.include "../../www/gnurl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.if ${OPSYS} == "Linux" && !empty(PKG_OPTIONS:Mbluez)
.include "../../wip/bluez-libs/buildlink3.mk"
.endif
.endif # GNUNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnunet
