# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.rocq
PKG_SUPPORTED_OPTIONS=	rocqide
PKG_SUGGESTED_OPTIONS=	rocqide

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		rocqide

.if !empty(PKG_OPTIONS:Mrocqide)
BUILDLINK_API_DEPENDS.ocaml-lablgtk3+=	ocaml-lablgtk3>=3.1.2
.include "../../x11/ocaml-lablgtk3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
DEPENDS+=	adwaita-icon-theme-[0-9]*:../../graphics/adwaita-icon-theme
DUNE_BUILD_PACKAGES+=	coqide-server rocqide
OPAM_INSTALL_FILES+=	coqide-server rocqide
PLIST.rocqide=		yes
.endif
