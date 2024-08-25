# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.avrdude
PKG_SUPPORTED_OPTIONS=	doc
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		doc
.if !empty(PKG_OPTIONS:Mdoc)
PLIST.doc=		yes
INFO_FILES=		yes
TEXINFO_REQD+=		5.0
USE_TOOLS+=		texi2html makeinfo
TOOL_DEPENDS+=		dvipsk-[0-9]*:../../print/dvipsk
TOOL_DEPENDS+=		tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts
TOOL_DEPENDS+=		tex-pdftex-[0-9]*:../../print/tex-pdftex
TOOL_DEPENDS+=		tex-texinfo-[0-9]*:../../print/tex-texinfo
# DragonFly has stripped makeinfo in the base - without texi2dvi.
.  if ${OPSYS} == "DragonFly"
TOOL_DEPENDS+=		gtexinfo-[0-9]*:../../devel/gtexinfo
.  endif
CMAKE_CONFIGURE_ARGS+=		-D BUILD_DOC=1
.else
CMAKE_CONFIGURE_ARGS+=		-D BUILD_DOC=0
.endif
