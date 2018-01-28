# $NetBSD: Makefile,v 1.2 2014/01/25 10:38:27 thomasklausner Exp $

DISTNAME=	YODA-1.0.2
PKGNAME=	yoda-1.0.2
CATEGORIES=	math
MASTER_SITES=	http://www.hepforge.org/archive/yoda/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://yoda.hepforge.org/
COMMENT=	Yet more Objects for Data Analysis
LICENSE=	gnu-gpl-v2

CHECK_PORTABILITY_SKIP=	configure

MAKE_JOBS=	2
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

PKG_OPTIONS_VAR=		PKG_OPTIONS.yoda
PKG_SUPPORTED_OPTIONS=		pyext root
PKG_SUGGESTED_OPTIONS=		pyext

.include "../../mk/bsd.options.mk"

.if !empty (PKG_OPTIONS:Mpyext)
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.py-cython+=	${PYPKGPREFIX}-cython>=0.12.1
.include "../../devel/py-cython/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pyext
.endif

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
