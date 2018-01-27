# $NetBSD: options.mk,v 1.1 2008/11/08 18:14:26 milosn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fvwm-crystal
PKG_SUPPORTED_OPTIONS=	habak hsetroot aterm urxvt mpc xmms
PKG_SUGGESTED_OPTIONS=	habak aterm

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mhabak)
DEPENDS+=	habak>=0.2.5:../../wip/habak
.endif

.if !empty(PKG_OPTIONS:Mhsetroot)
DEPENDS+=	hsetroot>=1.0.2:../../x11/hsetroot
.endif

.if !empty(PKG_OPTIONS:Materm)
DEPENDS+=	aterm>=1.0.0:../../x11/aterm
.endif

.if !empty(PKG_OPTIONS:Murxvt)
DEPENDS+=	rxvt-unicode>=0.8.3:../../x11/rxvt-unicode
.endif

.if !empty(PKG_OPTIONS:Mmpc)
DEPENDS+=	musicpd>=0.11.5:../../audio/musicpd
DEPENDS+=	mpc>=0.11.2:../../audio/mpc
.endif

.if !empty(PKG_OPTIONS:Mxmms)
DEPENDS+=	xmms>=1.2.11:../../audio/xmms
.endif
