# $NetBSD: options.mk$

PKG_OPTIONS_VAR=	PKG_OPTIONS.spyder
PKG_SUPPORTED_OPTIONS=	ipython numpy scipy sympy pandas pylint \
			flakes matplotlib psutil pygments pep8
PKG_SUGGESTED_OPTIONS+=	ipython numpy scipy sympy pandas pylint \
			flakes matplotlib pygments

PKG_OPTIONS_OPTIONAL_GROUPS+=	np plint
PKG_OPTIONS_GROUP.np=		scipy  pandas
PKG_OPTIONS_GROUP.plint=	pylint pyflakes pep8

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mipython)
DEPENDS+=	${PYPKGPREFIX}-ipython>=2.0.0:../../devel/py-ipython
.endif

.if !empty(PKG_OPTIONS:Mnumpy)
DEPENDS+=	${PYPKGPREFIX}-numpy>=1.9.2:../../math/py-numpy
.endif

.if !empty(PKG_OPTIONS:Mscipy)
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
.endif

.if !empty(PKG_OPTIONS:Mpandas)
DEPENDS+=	${PYPKGPREFIX}-pandas>=0.16.2:../../math/py-pandas
.endif

.if !empty(PKG_OPTIONS:Mmatplotlib)
DEPENDS+=	${PYPKGPREFIX}-matplotlib>=1.3.1:../../graphics/py-matplotlib
.endif

.if !empty(PKG_OPTIONS:Mpylint)
DEPENDS+=	${PYPKGPREFIX}-pylint>=1.4.3:../../devel/py-pylint
.endif

.if !empty(PKG_OPTIONS:Mflakes)
DEPENDS+=	${PYPKGPREFIX}-flakes>=0.9.2:../../devel/py-flakes
.endif

.if !empty(PKG_OPTIONS:Mpep8)
DEPENDS+=	${PYPKGPREFIX}-pep8>=1.6.2:../../devel/py-pep8
.endif

.if !empty(PKG_OPTIONS:Msympy)
DEPENDS+=	${PYPKGPREFIX}-sympy>=0.7.4.1:../../math/py-sympy
.endif
