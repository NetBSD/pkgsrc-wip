# $NetBSD$

DISTNAME=	clixon-pyapi-1.1.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=clicon/}
GITHUB_PROJECT=	clixon-pyapi
DISTFILES+=	${PKGNAME_NOREV}.tar.gz

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://www.clicon.org/
COMMENT=	Network services API for the Clixon controller
LICENSE=	apache-2.0

# Comments are from requirements.txt.
# Yes, these are not the same; requirements.txt list exact
# versions, while this pkg Makefile lists "newer than or equal".
#
# alabaster==0.7.16
DEPENDS+=	${PYPKGPREFIX}-alabaster>=0.7.16:../../textproc/py-alabaster
# attrs==23.2.0
DEPENDS+=	${PYPKGPREFIX}-attrs>=23.2.0:../../devel/py-attrs
# Babel==2.14.0
DEPENDS+=	${PYPKGPREFIX}-babel>=2.14.0:../../devel/py-babel
# certifi==2024.2.2
DEPENDS+=	${PYPKGPREFIX}-certifi>=2024.2.2:../../security/py-certifi
# charset-normalizer==3.3.2
DEPENDS+=	${PYPKGPREFIX}-charset-normalizer>=3.3.2:../../converters/py-charset-normalizer
# coverage==7.4.4
DEPENDS+=	${PYPKGPREFIX}-coverage>=7.4.4:../../devel/py-coverage
# daemonize==2.5.0
DEPENDS+=	${PYPKGPREFIX}-daemonize>=2.5.0:../../devel/py-daemonize
# docutils==0.20.1
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.20.1:../../textproc/py-docutils
# exceptiongroup==1.2.0
DEPENDS+=	${PYPKGPREFIX}-exceptiongroup>=1.2.0:../../devel/py-exceptiongroup
# idna==3.7
DEPENDS+=	${PYPKGPREFIX}-idna>=3.7:../../www/py-idna
# imagesize==1.4.1
DEPENDS+=	${PYPKGPREFIX}-imagesize>=1.4.1:../../graphics/py-imagesize
# iniconfig==2.0.0
DEPENDS+=	${PYPKGPREFIX}-iniconfig>=2.0.0:../../devel/py-iniconfig
# Jinja2==3.1.3
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.1.3:../../textproc/py-jinja2
# MarkupSafe==2.1.5
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=2.1.5:../../textproc/py-markupsafe
# packaging==24.0
DEPENDS+=	${PYPKGPREFIX}-packaging>=24.0:../../devel/py-packaging
# pluggy==1.4.0
DEPENDS+=	${PYPKGPREFIX}-pluggy>=1.4.0:../../devel/py-pluggy
# Pygments==2.17.2
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.17.2:../../textproc/py-pygments
# pytest==8.1.1
DEPENDS+=	${PYPKGPREFIX}-test>=8.1.1:../../devel/py-test
# pytest-cov==5.0.0
DEPENDS+=	${PYPKGPREFIX}-test-cov>=5.0.0:../../devel/py-test-cov
# requests==2.31.0
DEPENDS+=	${PYPKGPREFIX}-requests>=2.31.0:../../devel/py-requests
# snowballstemmer==2.2.0
DEPENDS+=	${PYPKGPREFIX}-snowballstemmer>=2.2.0:../../textproc/py-snowballstemmer
# Sphinx==7.3.6
DEPENDS+=	${PYPKGPREFIX}-sphinx>=7.3.6:../../textproc/py-sphinx
# sphinx-rtd-theme==2.0.0
DEPENDS+=	${PYPKGPREFIX}-sphinx-rtd-theme>=2.0.0:../../textproc/py-sphinx-rtd-theme
# sphinxcontrib-applehelp==1.0.8
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-applehelp>=1.0.8:../../textproc/py-sphinxcontrib-applehelp
# sphinxcontrib-devhelp==1.0.6
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-devhelp>=1.0.6:../../textproc/py-sphinxcontrib-devhelp
# sphinxcontrib-htmlhelp==2.0.5
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-htmlhelp>=2.0.5:../../textproc/py-sphinxcontrib-htmlhelp
# sphinxcontrib-jquery==4.1
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-jquery>=4.1:../../textproc/py-sphinxcontrib-jquery
# sphinxcontrib-jsmath==1.0.1
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-jsmath>=1.0.1:../../textproc/py-sphinxcontrib-jsmath
# sphinxcontrib-qthelp==1.0.7
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-qthelp>=1.0.7:../../textproc/py-sphinxcontrib-qthelp
# sphinxcontrib-serializinghtml==1.1.10
DEPENDS+=	${PYPKGPREFIX}-sphinxcontrib-serializinghtml>=1.1.10:../../textproc/py-sphinxcontrib-serializinghtml
# tomli==2.0.1
DEPENDS+=	${PYPKGPREFIX}-tomli>=2.0.1:../../textproc/py-tomli
# urllib3==2.2.1
DEPENDS+=	${PYPKGPREFIX}-urllib3>=2.2.1:../../www/py-urllib3
# xmltodict==0.13.0
DEPENDS+=	${PYPKGPREFIX}-xmltodict>=0.13.0:../../textproc/py-xmltodict

REPLACE_PYTHON+=	clixon_server.py

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
