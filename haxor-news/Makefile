# $NetBSD$

DISTNAME=	haxor-news-0.4.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_PYPI:=h/haxor-news/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/donnemartin/haxor-news
COMMENT=	Hacker News command line interface (CLI)
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-click>=5.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.3:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=1.0.0:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.0.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests>=2.4.3:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six

USE_LANGUAGES=	# none

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
