# $NetBSD: Makefile,v 1.4 2012/07/12 21:05:02 thomasklausner Exp $

DISTNAME=	python-magic-0.4.2
PKGNAME=	${PYPKGPREFIX}-magic-0.4.2
CATEGORIES=	sysutils python
MASTER_SITES=	http://pypi.python.org/packages/source/p/python-magic/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://pypi.python.org/pypi/python-magic/
COMMENT=	File type identification using libmagic
LICENSE=	python-software-foundation

PKG_DESTDIR_SUPPORT=	user-destdir

EGG_NAME=	${DISTNAME:S/-magic/_magic/}

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
