# $NetBSD$

DISTNAME=	gitsome-0.8.4
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gitsome/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/donnemartin/gitsome
COMMENT=	Supercharged Git/GitHub command line interface (CLI)
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-click>=5.1:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.3:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-docopt>=0.6.2:../../devel/py-docopt
DEPENDS+=	${PYPKGPREFIX}-feedparser>=5.2.1<6.0.0:../../textproc/py-feedparser5
DEPENDS+=	${PYPKGPREFIX}-numpydoc>=0.5:../../textproc/py-numpydoc
DEPENDS+=	${PYPKGPREFIX}-ply>=3.4:../../devel/py-ply
DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=2.0.0:../../devel/py-prompt_toolkit2
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.0.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-pytz>=2016.3:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.8.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-uritemplate>=1.0.0:../../textproc/py-uritemplate

USE_LANGUAGES=	# none

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/gitsome.bat
	${RM} ${DESTDIR}${PREFIX}/bin/xonsh.bat

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
