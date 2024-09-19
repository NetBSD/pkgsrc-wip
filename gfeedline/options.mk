# $NetBSD: options.mk,v 1.2 2013/12/22 17:04:23 noud4 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gfeedline
PKG_SUPPORTED_OPTIONS=	proxy spellcheck
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mproxy)
#DEPENDS+=	${PYPKGPREFIX}-libproxy-[0-9]*:../../wip/py-libproxy		# TODO
.endif

#gnome-sushi									# TODO

.if !empty(PKG_OPTIONS:Mspellcheck)
#DEPENDS+=	${PYPKGPREFIX}-gtkspellcheck-[0-9]*:../../wip/py-gtkspellcheck	# TODO
.endif
