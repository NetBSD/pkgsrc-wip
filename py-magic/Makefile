# $NetBSD: Makefile,v 1.3 2012/07/12 14:48:27 khorben Exp $

DISTNAME=	python-magic-0.4.2
PKGNAME=	${PYPKGPREFIX}-magic-0.4.2
CATEGORIES=	sysutils python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-magic/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://pypi.python.org/pypi/python-magic/
COMMENT=	File type identification using libmagic
LICENSE=	python-software-foundation

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
