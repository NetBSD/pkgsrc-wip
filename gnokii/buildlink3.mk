# $NetBSD: buildlink3.mk,v 1.4 2013/02/28 11:24:15 othyro Exp $

BUILDLINK_TREE+=	gnokii

.if !defined(GNOKII_BUILDLINK3_MK)
GNOKII_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnokii+=	gnokii>=0.6.14
BUILDLINK_PKGSRCDIR.gnokii?=	../../wip/gnokii

pkgbase := gnokii
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gnokii:Mical)
.include "../../time/libical/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gnokii:Mlibusb)
.include "../../devel/libusb/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gnokii:Mmysql)
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gnokii:Mpcsc)
.include "../../security/pcsc-lite/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gnokii:Mpgsql)
.include "../../mk/pgsql.buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gnokii:Mreadline)
.include "../../devel/readline/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gnokii:Msqlite3)
.include "../../databases/sqlite3/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gnokii:Mx11)
.include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.gnokii:Mxpm)
.  if empty(PKG_BUILD_OPTIONS.gnokii:Mx11)
.include "../../x11/libXpm/buildlink3.mk"
.  endif
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.endif # GNOKII_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnokii
