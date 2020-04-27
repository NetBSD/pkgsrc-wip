# $NetBSD: Makefile,v 1.55 2020/04/27 19:54:53 leot Exp $

DISTNAME=	tldr-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/tldr/}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/tldr-pages/tldr-python-client
COMMENT=	Python command line client for tldr
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-colorama-[0-9]*:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-termcolor-[0-9]*:../../devel/py-termcolor

USE_LANGUAGES=			# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
