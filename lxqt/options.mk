# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.lxqt
PKG_SUPPORTED_OPTIONS=	openbox
PKG_SUGGESTED_OPTIONS=	openbox

.include "../../mk/bsd.options.mk"

# \todo: When importing, add openbox to options file.
.if !empty(PKG_OPTIONS:Mopenbox)
DEPENDS+=	openbox>=3.6.1:../../wm/openbox
DEPENDS+=	obconf-qt>=0.14.1:../../wip/obconf-qt
.endif
