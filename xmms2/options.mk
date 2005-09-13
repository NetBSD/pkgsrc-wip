# $NetBSD: options.mk,v 1.2 2005/09/13 21:18:09 leonardschmidt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xmms2
PKG_SUPPORTED_OPTIONS=	curl flac ogg pyrex ruby sid
PKG_SUGGESTED_OPTIONS=	curl flac ogg pyrex

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcurl)
.  include "../../www/curl/buildlink3.mk"
PLIST_SUBST+=		CURL=""
.else
PLIST_SUBST+=		CURL="@comment "
EXCLUDE+=		curl
.endif

.if !empty(PKG_OPTIONS:Mflac)
.  include "../../audio/flac/buildlink3.mk"
PLIST_SUBST+=		FLAC=""
.else
PLIST_SUBST+=		FLAC="@comment "
EXCLUDE+=		flac
.endif

.if !empty(PKG_OPTIONS:Mogg)
.  include "../../audio/libvorbis/buildlink3.mk"
PLIST_SUBST+=		OGG=""
.else
PLIST_SUBST+=		OGG="@comment "
EXCLUDE+=		ogg
.endif

.if !empty(PKG_OPTIONS:Mpyrex)
PY_PATCHPLIST=		yes
BUILD_DEPENDS=		${PYPKGPREFIX}-pyrex>=0.8.1:../../lang/py-pyrex
.  include "../../lang/python/extension.mk"
PLIST_SUBST+=		PYREX=""
.else
EXCLUDE+=		python
PLIST_SUBST+=		PYREX="@comment "
.endif

.if !empty(PKG_OPTIONS:Mruby)
RUBY_VERSION_SUPPORTED=	18
.  include "../../lang/ruby/buildlink3.mk"
.  include "../../lang/ruby/rubyversion.mk"
PLIST_SUBST+=		RUBY=""
.else
EXCLUDE+=		ruby
PLIST_SUBST+=		RUBY="@comment "
.endif

.if !empty(PKG_OPTIONS:Msid)
.  include "../../audio/libsidplay/buildlink3.mk"
DEPENDS+=		sidplay-[0-9]*:../../audio/sidplay
PLIST_SUBST+=		SID=""
.else
EXCLUDE+=		sid
PLIST_SUBST+=		SID="@comment "
.endif
