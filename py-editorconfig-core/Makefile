# $NetBSD: Makefile,v 1.4 2014/11/19 20:12:29 nros Exp $

DISTNAME=	editorconfig-core-py-0.12.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-py//1}
CATEGORIES=	devel
MASTER_SITES=	-https://github.com/editorconfig/editorconfig-core-py/archive/v${PKGVERSION}.tar.gz

MAINTAINER=	nros@users.sourceforge.net
HOMEPAGE=	http://editorconfig.org/
COMMENT=	Editorconfig python library
LICENSE=	python-software-foundation AND modified-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

.include "../../lang/python/distutils.mk"
# url2pkg-marker (please do not remove this line.)
.include "../../mk/bsd.pkg.mk"
