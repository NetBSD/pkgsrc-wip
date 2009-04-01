# $NetBSD: options.mk,v 1.11 2009/04/01 12:53:47 thomasklausner Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.xmms2
PKG_SUPPORTED_OPTIONS=	faad flac gnomevfs modplug ogg pyrex ruby perl
PKG_SUGGESTED_OPTIONS=	flac gnomevfs modplug ogg

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS} gamin
.if !empty(PKG_OPTIONS:Mfaad)
.  include "../../audio/faad2/buildlink3.mk"
PLIST.faad=		yes
.endif

PLIST_VARS+=	flac
.if !empty(PKG_OPTIONS:Mflac)
.  include "../../audio/flac/buildlink3.mk"
PLIST.flac=		yes
.endif

# currently won't work
#.if !empty(PKG_OPTIONS:Mgamin)
#.  include "../../sysutils/gamin/buildlink3.mk"
#PLIST.gamin=		yes
#.endif

.if !empty(PKG_OPTIONS:Mgnomevfs)
.  include "../../sysutils/gnome-vfs/buildlink3.mk"
PLIST.gnomevfs=		yes
.endif

.if !empty(PKG_OPTIONS:Mmodplug)
.  include "../../audio/libmodplug/buildlink3.mk"
PLIST.modplug=		yes
.endif

.if !empty(PKG_OPTIONS:Mogg)
.  include "../../audio/libvorbis/buildlink3.mk"
PLIST.ogg=		yes
.endif

.if !empty(PKG_OPTIONS:Mperl)
.   include "../../lang/perl5/buildlink3.mk"
PLIST.perl=		yes
USE_TOOLS+=		perl
.endif

.if !empty(PKG_OPTIONS:Mpyrex)
PY_PATCHPLIST=		yes
BUILD_DEPENDS+=		${PYPKGPREFIX}-pyrex>=0.8.1:../../lang/py-pyrex
.  include "../../lang/python/extension.mk"
PLIST.pyrex=		yes
.endif

.if !empty(PKG_OPTIONS:Mruby)
USE_RUBY_DIST_SUBDIR=	no
.  include "../../lang/ruby/buildlink3.mk"
PLIST.ruby=		yes
.endif

# this is currently disabled by the package itself.
.if !empty(PKG_OPTIONS:Msidplay)
.  include "../../audio/libsidplay/buildlink3.mk"
DEPENDS+=		sidplay-[0-9]*:../../audio/sidplay
PLIST.sidplay=		yes
.endif
