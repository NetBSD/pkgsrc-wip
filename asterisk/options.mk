# $NetBSD: options.mk,v 1.2 2005/03/30 21:16:17 riz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.asterisk
PKG_SUPPORTED_OPTIONS=	zaptel
.include "../../mk/bsd.options.mk"

# Can't use the default PLIST_SRC handling, since we may need to
# add PLIST.zaptel

PLIST_SRC=		${PKGDIR}/PLIST.common
.  if exists(${PKGDIR}/PLIST.${OPSYS})
PLIST_SRC+=		${PKGDIR}/PLIST.${OPSYS}
.  endif

.if !empty(PKG_OPTIONS:Mzaptel)
# zaptel only supported under NetBSD at the moment
.  include "../../wip/zaptel-netbsd/buildlink3.mk"
MAKE_FLAGS+=	ASTERISK_USE_ZAPTEL=1
PLIST_SRC+=		${PKGDIR}/PLIST.zaptel
.endif

PLIST_SRC+=		${PKGDIR}/PLIST.common_end
