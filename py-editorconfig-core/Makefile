# $NetBSD: Makefile,v 1.3 2014/04/23 19:50:38 nros Exp $

DISTNAME=	editorconfig-core-py-0.11.4
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
