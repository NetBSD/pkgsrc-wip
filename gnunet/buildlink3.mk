# $NetBSD$

BUILDLINK_TREE+=	gnunet

.if !defined(GNUNET_BUILDLINK3_MK)
GNUNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnunet+=	gnunet>=0.11.0
BUILDLINK_PKGSRCDIR.gnunet?=	../../wip/gnunet

pkgbase:= gnunet
.include "../../mk/pkg-build-options.mk"

#.include "../../audio/libopus/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/libextractor/buildlink3.mk"
.include "../../devel/libgsf/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
#.include "../../multimedia/gstreamer1/buildlink3.mk"
#.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
#.include "../../multimedia/libogg/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../textproc/jansson/buildlink3.mk"
.include "../../www/gnurl/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif # GNUNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnunet
