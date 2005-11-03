# $NetBSD: options.mk,v 1.7 2005/11/03 08:31:35 leonardschmidt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xmms2
PKG_SUPPORTED_OPTIONS=	curl flac ogg pyrex ruby
PKG_SUGGESTED_OPTIONS=	curl flac ogg ruby

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcurl)
.  include "../../www/curl/buildlink3.mk"
PLIST_SUBST+=		CURL=""
.else
PLIST_SUBST+=		CURL="@comment "
EXCLUDES+=		curl
.endif

.if !empty(PKG_OPTIONS:Mflac)
.  include "../../audio/flac/buildlink3.mk"
PLIST_SUBST+=		FLAC=""
.else
PLIST_SUBST+=		FLAC="@comment "
EXCLUDES+=		flac
.endif

.if !empty(PKG_OPTIONS:Mogg)
.  include "../../audio/libvorbis/buildlink3.mk"
PLIST_SUBST+=		OGG=""
.else
PLIST_SUBST+=		OGG="@comment "
EXCLUDES+=		ogg
.endif

.if !empty(PKG_OPTIONS:Mpyrex)
PY_PATCHPLIST=		yes
BUILD_DEPENDS+=		${PYPKGPREFIX}-pyrex>=0.8.1:../../lang/py-pyrex
.  include "../../lang/python/extension.mk"
PLIST_SUBST+=		PYREX=""
.else
EXCLUDES+=		python
PLIST_SUBST+=		PYREX="@comment "
.endif

.if !empty(PKG_OPTIONS:Mruby)
USE_RUBY_DIST_SUBDIR=	no
.  include "../../lang/ruby/buildlink3.mk"
PLIST_SUBST+=		RUBY=""
.else
EXCLUDES+=		ruby
PLIST_SUBST+=		RUBY="@comment "
.endif

# this is currently disabled by the package itself.
.if !empty(PKG_OPTIONS:Msid)
.  include "../../audio/libsidplay/buildlink3.mk"
DEPENDS+=		sidplay-[0-9]*:../../audio/sidplay
PLIST_SUBST+=		SID=""
.else
EXCLUDES+=		sid
PLIST_SUBST+=		SID="@comment "
.endif
