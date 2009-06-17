# $NetBSD: Makefile,v 1.1.1.1 2009/06/17 23:18:37 jihbed Exp $
#

DISTNAME=	pyflakes-0.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	http://launchpad.net/pyflakes/main/0.2.1/+download/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://launchpad.net/pyflakes
COMMENT=	Passive checker of Python programs
LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG= yes

USE_LANGUAGES=	# none

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
