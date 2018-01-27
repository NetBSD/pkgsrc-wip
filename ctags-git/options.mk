# $NetBSD: options.mk,v 1.1 2015/04/27 21:17:15 jonthn Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ctags
PKG_SUPPORTED_OPTIONS=		exctags emacs

.include "../../mk/bsd.options.mk"

# Package-specific option-handling

###
### Use prefixed program name 'exctags'
###
.if !empty(PKG_OPTIONS:Mexctags)
CONFIGURE_ARGS+=	--program-prefix=ex
PLIST_SUBST+=		PREFIX_PROGRAM="ex"
.else
PLIST_SUBST+=		PREFIX_PROGRAM=""
.endif

###
### Generate tool/link for emacs support
###
PLIST_VARS+=		emacs
.if !empty(PKG_OPTIONS:Memacs)
CONFIGURE_ARGS+=	--enable-etags
PLIST.emacs=		yes
.endif
