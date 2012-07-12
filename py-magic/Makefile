# $NetBSD: Makefile,v 1.2 2012/07/12 14:26:08 khorben Exp $

DISTNAME=	python-magic-0.4.2
PKGNAME=	${PYPKGPREFIX}-magic-0.4.2
CATEGORIES=	sysutils python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-magic/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://pypi.python.org/pypi/python-magic/
COMMENT=	File type identification using libmagic
LICENSE=	python-software-foundation

DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
