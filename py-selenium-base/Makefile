# $NetBSD$

GITHUB_PROJECT=	SeleniumBase
GITHUB_TAG=	v1.49.25
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-selenium-base-1.49.25
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=seleniumbase/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/seleniumbase/SeleniumBase
COMMENT=	Complete framework for Web-UI testing
LICENSE=	mit

USE_TOOLS+=	bash

#FORCED REFUSE= PY27!
PYTHON_VERSIONS_INCOMPATIBLE=	27

#DEPENDENCY FOR Python>=3.7
DEPENDS+=       ${PYPKGPREFIX}-zipp>=1.2.0:../../archivers/py-zipp
DEPENDS+=       ${PYPKGPREFIX}-chardet>=3.0.4:../../converters/py-chardet
DEPENDS+=       ${PYPKGPREFIX}-pymysql>=0.10.0:../../databases/py-pymysql
DEPENDS+=       ${PYPKGPREFIX}-flake8>=3.8.4:../../devel/py-flake8
DEPENDS+=       ${PYPKGPREFIX}-ipython>=7.18.1:../../devel/py-ipython
DEPENDS+=       ${PYPKGPREFIX}-packaging>=19.2:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=4.1.2:../../devel/py-setuptools_scm
DEPENDS+=       ${PYPKGPREFIX}-test-rerunfailures>=9.0:../../devel/py-test-rerunfailures
DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov
DEPENDS+=	${PYPKGPREFIX}-test-forked>=1.1.3:../../devel/py-test-forked
DEPENDS+=       ${PYPKGPREFIX}-parso>=0.8.0:../../lang/py-parso
DEPENDS+=       ${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-cssselect>=1.1.0:../../textproc/py-cssselect
DEPENDS+=	${PYPKGPREFIX}-wheel>=:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-test-html>=1.17.0:../../wip/py-test-html
DEPENDS+=	${PYPKGPREFIX}-soupsieve>=1.9.5:../../www/py-soupsieve
DEPENDS+=	${PYPKGPREFIX}-boto-[0-9]*:../../net/py-boto
DEPENDS+=	${PYPKGPREFIX}-idna>=2.10:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-pluggy>=0.13.1:../../devel/py-pluggy
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.3.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.3.3:../../devel/py-traitlets
DEPENDS+=	${PYPKGPREFIX}-otp>=2.4.0:../../wip/py-otp
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata>=1.7.0:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-virtualenv>=16.7.9:../../devel/py-virtualenv
DEPENDS+=	${PYPKGPREFIX}-jedi>=0.17.2:../../editors/py-jedi
DEPENDS+=	${PYPKGPREFIX}-pip>=20.2.3:../../devel/py-pip
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.25.10:../../www/py-urllib3
DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-more-itertools>=8.5.0:../../devel/py-more-itertools
DEPENDS+=	${PYPKGPREFIX}-coverage>=0.7.4:../../devel/py-coverage
#DEPENDS+=       ${PYPKGPREFIX}-brython>=0.7.4:../../wip/py-brython
DEPENDS+=	${PYPKGPREFIX}-nose>=1.3.7:../../devel/py-nose
DEPENDS+=	${PYPKGPREFIX}-parso>=0.8.0:../../lang/py-parso
DEPENDS+=	${PYPKGPREFIX}-parameterized>=0.7.4:../../devel/py-parameterized
#DEPENDS+=       ${PYPKGPREFIX}-prompt_toolkit>=3.0.7:../../devel/py-prompt_toolkit
DEPENDS+=	${PYPKGPREFIX}-rich>=7.1.0:../../wip/py-rich
DEPENDS+=	${PYPKGPREFIX}-certifi>=2020.6.20:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.3:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.9.2:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.7.4:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.5.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-pdfminer-six-[0-9]*:../../wip/py-pdfminer-six
DEPENDS+=	${PYPKGPREFIX}-test-metadata>=1.7.0:../../wip/py-test-metadata
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=0.7.4:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-selenium>=3.141.0:../../www/py-selenium

WRKSRC=		${WRKDIR}/SeleniumBase-1.49.25

REPLACE_BASH+=	seleniumbase/utilities/selenium_grid/font_color
REPLACE_BASH+=	seleniumbase/utilities/selenium_grid/grid-hub
REPLACE_BASH+=	seleniumbase/utilities/selenium_grid/start-grid-hub.sh
REPLACE_BASH+=	seleniumbase/utilities/selenium_grid/register-grid-node.sh
REPLACE_BASH+=	seleniumbase/utilities/selenium_grid/grid-node

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
