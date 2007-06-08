# $NetBSD: Makefile,v 1.10 2007/06/08 05:50:51 uebayasi Exp $

DISTNAME=	emacs-22.1
CATEGORIES=	editors
COMMENT=	GNU editing macros (editor)

#.include "../../editors/emacs22/Makefile.common"
.include "../../wip/emacs22/Makefile.common"

CONFLICTS+=	emacs-nox11-[0-9]*

CONFIGURE_ARGS+=	--srcdir=${WRKSRC:Q}

PKG_OPTIONS_VAR=	PKG_OPTIONS.emacs
PKG_OPTIONS_OPTIONAL_GROUPS=	toolkit
PKG_OPTIONS_GROUP.toolkit=	motif gtk xaw
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmotif) || !empty(PKG_OPTIONS:Mgtk) || !empty(PKG_OPTIONS:Mxaw)

CONFIGURE_ARGS+=	--with-x
CONFIGURE_ARGS+=	--with-xpm
CONFIGURE_ARGS+=	--with-jpeg
CONFIGURE_ARGS+=	--with-tiff
CONFIGURE_ARGS+=	--with-gif
CONFIGURE_ARGS+=	--with-png

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"

.if !empty(PKG_OPTIONS:Mmotif)
.include "../../mk/motif.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=motif
.elif !empty(PKG_OPTIONS:Mgtk)
USE_TOOLS+=		pkg-config
.include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=gtk
.elif !empty(PKG_OPTIONS:Mxaw)
.include "../../mk/xaw.buildlink3.mk"
CONFIGURE_ARGS+=	--with-x-toolkit=athena
.endif

# need 4.1.0b1 or higher (a bug in 4.1.0 can crash Emacs)
BUILDLINK_API_DEPENDS.libungif+=	libungif>=4.1.0.1
.endif

.include "../../mk/bsd.pkg.mk"
