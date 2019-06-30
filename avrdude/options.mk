# $NetBSD: options.mk,v 1.3 2015/07/20 23:03:24 dholland Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.avrdude
PKG_SUPPORTED_OPTIONS+=		doc
PKG_SUGGESTED_OPTIONS=
PLIST_VARS+=			doc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdoc)
CONFIGURE_ARGS+=	--enable-doc

BUILD_DEPENDS+=		dvipsk-[0-9]*:../../print/dvipsk
BUILD_DEPENDS+=		tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
BUILD_DEPENDS+=		tex-pdftex-[0-9]*:../../print/tex-pdftex
TEXINFO_REQD=		4.9
USE_TOOLS+=		makeinfo texi2html yacc lex

# DragonFly has stripped makeinfo in the base - without texi2dvi.
.  if ${OPSYS} == "DragonFly"
BUILD_DEPENDS+=		gtexinfo-[0-9]*:../../devel/gtexinfo
.  endif
PLIST.doc=		yes

.else
CONFIGURE_ARGS+=	--disable-doc
.endif
