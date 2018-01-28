# $NetBSD: options.mk,v 1.2 2015/04/30 22:22:00 jonthn Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.neovim
PKG_SUPPORTED_OPTIONS=	python ruby jemalloc
PKG_SUGGESTED_OPTIONS=	python ruby

.include "../../mk/bsd.options.mk"

###
### Support Python (add dependency)
###
.if !empty(PKG_OPTIONS:Mpython)
DEPENDS+=	${PYPKGPREFIX}-neovim-[0-9]*:../../wip/py-neovim

.include "../../lang/python/pyversion.mk"
.endif

###
### Support Ruby (add dependency)
###
.if !empty(PKG_OPTIONS:Mruby)
DEPENDS+=	${RUBY_PKGPREFIX}-neovim-[0-9]*:../../wip/ruby-neovim

.include "../../lang/ruby/rubyversion.mk"
.endif

###
### Use jemalloc for memory allocation
###
.if !empty(PKG_OPTIONS:Mjemalloc)
.include "../../devel/jemalloc/buildlink3.mk"
.else
CMAKE_ARGS+= -DENABLE_JEMALLOC=OFF
.endif
