# $NetBSD: options.mk,v 1.2 2015/04/30 22:22:00 jonthn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.neovim
PKG_SUPPORTED_OPTIONS=	python jemalloc
PKG_SUGGESTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

###
### Support Python (add dependency)
###
.  if !empty(PKG_OPTIONS:Mpython)
DEPENDS+=       ${PYPKGPREFIX}-neovim-[0-9]*:../../wip/py-neovim

.include "../../lang/python/pyversion.mk"
.  endif

###
### Use jemalloc for memory allocation
###
.  if !empty(PKG_OPTIONS:Mjemalloc)
.include "../../devel/jemalloc/buildlink3.mk"
.  endif
