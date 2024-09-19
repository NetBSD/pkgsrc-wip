# $NetBSD: options.mk,v 1.2 2010/06/16 12:30:51 asau Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gretl

# Options:

PKG_SUPPORTED_OPTIONS+=		readline
# provides a nice editable command line in gretlcli, the command-line program

PKG_SUPPORTED_OPTIONS+=		png
# enhance gretl's ability to work with PNG graphs created by gnuplot

PKG_SUPPORTED_OPTIONS+=		gnome
# gretl is integrated into the gnome desktop
# (file icons and associations, help system and so on)

PKG_SUPPORTED_OPTIONS+=		gmp
# supports gretl's Multiple Precision OLS plugin

# gtksourceview optional      syntax highlighting for gretl scripts

PKG_SUGGESTED_OPTIONS=		readline

.include "../../mk/bsd.options.mk"

.for option in ${PKG_SUPPORTED_OPTIONS}
.  if !empty(PKG_OPTIONS:M${option})
PLIST_SUBST+=	${option}=""
.  else
PLIST_SUBST+=	${option}="@comment "
.  endif
.endfor

.if !empty(PKG_OPTIONS:Mreadline)
USE_GNU_READLINE=	YES
.include "../../devel/readline/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgmp)
.include "../../devel/gmp/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
.endif

# More?
#.include "../../x11/gtk2/buildlink3.mk"
