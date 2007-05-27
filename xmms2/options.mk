# $NetBSD: options.mk,v 1.9 2007/05/27 17:46:28 tnn2 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xmms2
PKG_SUPPORTED_OPTIONS=	faad flac gnomevfs modplug ogg pyrex ruby perl
PKG_SUGGESTED_OPTIONS=	flac gnomevfs modplug ogg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mfaad)
.  include "../../audio/faad2/buildlink3.mk"
PLIST_SUBST+=		FAAD=""
.else
PLIST_SUBST+=		FAAD="@comment "
.endif

.if !empty(PKG_OPTIONS:Mflac)
.  include "../../audio/flac/buildlink3.mk"
PLIST_SUBST+=		FLAC=""
.else
PLIST_SUBST+=		FLAC="@comment "
.endif

.if !empty(PKG_OPTIONS:Mgnomevfs)
.  include "../../sysutils/gnome-vfs2/buildlink3.mk"
PLIST_SUBST+=		GNOMEVFS=""
.else
PLIST_SUBST+=		GNOMEVFS="@comment "
.endif

.if !empty(PKG_OPTIONS:Mmodplug)
.  include "../../audio/libmodplug/buildlink3.mk"
PLIST_SUBST+=		MODPLUG=""
.else
PLIST_SUBST+=		MODPLUG="@comment "
.endif

.if !empty(PKG_OPTIONS:Mogg)
.  include "../../audio/libvorbis/buildlink3.mk"
PLIST_SUBST+=		OGG=""
.else
PLIST_SUBST+=		OGG="@comment "
.endif

.if !empty(PKG_OPTIONS:Mperl)
.   include "../../lang/perl5/buildlink3.mk"
PLIST_SUBST+=		PERL=""
USE_TOOLS+=		perl
.else
PLIST_SUBST+=		PERL="@comment "
.endif

.if !empty(PKG_OPTIONS:Mpyrex)
PY_PATCHPLIST=		yes
BUILD_DEPENDS+=		${PYPKGPREFIX}-pyrex>=0.8.1:../../lang/py-pyrex
.  include "../../lang/python/extension.mk"
PLIST_SUBST+=		PYREX=""
.else
PLIST_SUBST+=		PYREX="@comment "
.endif

.if !empty(PKG_OPTIONS:Mruby)
USE_RUBY_DIST_SUBDIR=	no
.  include "../../lang/ruby/buildlink3.mk"
PLIST_SUBST+=		RUBY=""
.else
PLIST_SUBST+=		RUBY="@comment "
.endif

# this is currently disabled by the package itself.
.if !empty(PKG_OPTIONS:Msid)
.  include "../../audio/libsidplay/buildlink3.mk"
DEPENDS+=		sidplay-[0-9]*:../../audio/sidplay
PLIST_SUBST+=		SID=""
.else
PLIST_SUBST+=		SID="@comment "
.endif
