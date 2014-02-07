# $NetBSD $

PKG_OPTIONS_VAR=	PKG_OPTIONS.spyder
PKG_SUPPORTED_OPTIONS=	rope numpy scipy ipython1 matplotlib Pillow
PKG_SUGGESTED_OPTIONS=	ipython1 numpy matplotlib rope

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mipython1)
DEPENDS+=	${PYPKGPREFIX}-ipython>=1.1.0:../../devel/py-ipython1
.endif

.if !empty(PKG_OPTIONS:Mrope)
.include "../../devel/py-rope/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mnumpy)
.include "../../math/py-numpy/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mscipy)
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.12.1:../../math/py-scipy
.endif

.if !empty(PKG_OPTIONS:Mmatplotlib)
.include "../../graphics/py-matplotlib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:MPillow)
DEPENDS+=	${PYPKGPREFIX}-Pillow>=2.3.0:../../graphics/py-Pillow
PLIST.sqlite=	yes
.endif
