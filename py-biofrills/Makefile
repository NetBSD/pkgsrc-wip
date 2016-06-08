# $NetBSD: Makefile,v 1.1 2014/06/20 20:22:26 jihbed Exp $

DISTNAME=	biofrills-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/biofrills/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://github.com/etal/biofrills
COMMENT=	Bioinformatics utilities for molecular sequence analysis
LICENSE=	modified-bsd

PKG_OPTIONS_VAR=	PKG_OPTIONS.biofrills
PKG_SUPPORTED_OPTIONS=	cython

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcython)
.include "../../devel/py-cython/buildlink3.mk"
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
