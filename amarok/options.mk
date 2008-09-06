# $NetBSD: options.mk,v 1.2 2008/09/06 23:27:13 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.amarok
PKG_SUPPORTED_OPTIONS=	libgpod libmp4v2 libmtp libnjb libvisual mp3tunes mysql plasma
PKG_SUGGESTED_OPTIONS=	libgpod libmp4v2 libmtp libvisual mp3tunes plasma

# XXX: mysql doesn't work yet, probably needs more cmake magic
# XXX: libnjb is currently not supported

# XXX: not packaged yet
# libifp, 1.0.0.2: Support iRiver iFP audio devices <http://ifp-driver.sourceforge.net/libifp/>

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibgpod)
BUILDLINK_API_DEPENDS.libgpod+=	libgpod>=0.6.0nb1
.include "../../audio/libgpod/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibmp4v2)
.include "../../multimedia/libmp4v2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibmtp)
.include "../../devel/libmtp/buildlink3.mk"
.endif

#.if !empty(PKG_OPTIONS:Mlibnjb)
#.include "../../wip/libnjb/buildlink3.mk"
#.endif

.if !empty(PKG_OPTIONS:Mlibvisual)
.include "../../audio/libvisual/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmp3tunes)
.include "../../chat/loudmouth/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
# XXX: make sure qt4-libs have glib enabled
.endif

.if !empty(PKG_OPTIONS:Mmysql)
MYSQL_VERSIONS_ACCEPTED=	41
.include "../../mk/mysql.buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mplasma)
.include "../../wip/kdebase-workspace4/buildlink3.mk"
.endif
