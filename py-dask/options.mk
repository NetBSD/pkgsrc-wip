# $NetBSD: options.mk,v 1.5 2019/04/26 13:13:46 maya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-dask
PKG_SUPPORTED_OPTIONS=	cityhash cytoolz parquet graphviz psutil scipy skimage xarray sqlalchemy
PKG_SUGGESTED_OPTIONS=	cityhash cytoolz parquet psutil scipy skimage xarray sqlalchemy

.include "../../mk/bsd.options.mk"

# Cityhash is an optional dependency for faster string hashing
.if !empty(PKG_OPTIONS:Mcityhash)
DEPENDS+=	${PYPKGPREFIX}-cityhash-[0-9]*:../../wip/py-cityhash
.endif

# cytoolz is an optional dependency, will replace devel/py-toolz
.if !empty(PKG_OPTIONS:Mcytoolz)
DEPENDS+=	${PYPKGPREFIX}-cytoolz-[0-9]*:../../devel/py-cytoolz
.endif

# enable reading parquet files
.if !empty(PKG_OPTIONS:Mparquet)
# TODO Also needs pyarrow
DEPENDS+=	${PYPKGPREFIX}-fastparquet-[0-9]*:../../wip/py-fastparquet
DEPENDS+=	${PYPKGPREFIX}-pyarrow-[0-9]*:../../wip/py-apache-arrow
.endif

# graphviz is used to display the task dependencies
.if !empty(PKG_OPTIONS:Mgraphviz)
DEPENDS+=	${PYPKGPREFIX}-graphviz-[0-9]*:../../graphics/py-graphviz
.endif

# SQL Support
.if !empty(PKG_OPTIONS:Msqlalchemy)
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy-[0-9]*:../../databases/py-sqlalchemy
.endif

# Enable scikit-image
.if !empty(PKG_OPTIONS:Mskimage)
DEPENDS+=	${PYPKGPREFIX}-scikit-image-[0-9]*:../../math/py-scikit-image
.endif

# X-array support
.if !empty(PKG_OPTIONS:Mxarray)
DEPENDS+=	${PYPKGPREFIX}-xarray-[0-9]*:../../math/py-xarray
.endif

# scipy support
.if !empty(PKG_OPTIONS:Mscipy)
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy
.endif

# Better cpu/memory/resource reporting
.if !empty(PKG_OPTIONS:Mpsutil)
DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
.endif
