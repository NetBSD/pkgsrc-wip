# $NetBSD: Makefile,v 1.3 2014/05/09 07:38:46 thomasklausner Exp $

DISTNAME=	dexy-0.9.9.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dexy/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://dexy.it/
COMMENT=	Document Automation
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-chardet>=2.1.1:../../converters/py-chardet
DEPENDS+=	ply>=3.3:../../devel/ply
DEPENDS+=	${PYPKGPREFIX}-pexpect>=2.3:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-requests>=1.2.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.11:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-markdown>=2.2.1:../../textproc/py-markdown
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-yaml>=3.10:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-dexy_viewer>=0.0.4:../../wip/py-dexy_viewer
DEPENDS+=	${PYPKGPREFIX}-inflection>=0.2.0:../../wip/py-inflection

WRKSRC=		${WRKDIR}/dexy-0.9.9.5

USE_LANGUAGES=	# none
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # py-docutils

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
