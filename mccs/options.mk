# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.mccs
PKG_OPTIONS_REQUIRED_GROUPS=	solver
PKG_OPTIONS_GROUP.solver=	lpsolve glpk
PKG_SUPPORTED_OPTIONS=		lpsolve glpk
PKG_SUGGESTED_OPTIONS=		lpsolve

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mglpk)
BUILD_MAKE_FLAGS+=USEGLPK=1
.include "../../math/glpk/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlpsolve)
BUILD_MAKE_FLAGS+=USELPSOLVE=1
.include "../../math/lp_solve/buildlink3.mk"
.endif
