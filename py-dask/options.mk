# $NetBSD: options.mk,v 1.5 2019/04/26 13:13:46 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-dask
PKG_SUPPORTED_OPTIONS=	cityhash cytoolz fastparquet psutil scipy sqlalchemy
PKG_SUGGESTED_OPTIONS=	cityhash cytoolz psutil scipy sqlalchemy

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcityhash)
DEPENDS+=	cityhash-[0-9]*:../../wip/py-cityhash
.endif

.if !empty(PKG_OPTIONS:Mcytoolz)
DEPENDS+=	${PYPKGPREFIX}-cytoolz-[0-9]*:../../devel/py-cytoolz
.endif

.if !empty(PKG_OPTIONS:Mfastparquet)
DEPENDS+=	fastparquet-[0-9]*:../../wip/py-fastparquet
.endif

.if !empty(PKG_OPTIONS:Msqlalchemy)
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-[0-9]*:../../databases/py-sqlalchemy
.endif

.if !empty(PKG_OPTIONS:Mscipy)
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
.endif
.if !empty(PKG_OPTIONS:Mpsutil)
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
.endif
