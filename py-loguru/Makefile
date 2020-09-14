# $NetBSD$

DISTNAME=	loguru-0.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	https://files.pythonhosted.org/packages/6d/aa/1c523f7955c718f603d0a7c6e72f0593e7335d967fabdce589ab86afaa9e/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/Delgan/loguru
COMMENT=	Python logging made (stupidly) simple
LICENSE=	mit

#BUILD_DEPENDS+=	${PYPKGPREFIX}-black>=19.3b0;python_version>='3.6':../../wip/py-black
BUILD_DEPENDS+=	${PYPKGPREFIX}-codecov>=2.0.15:../../wip/py-codecov
BUILD_DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.4:../../comms/py-colorama
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.7.7:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-isort>=4.3.20:../../devel/py-isort
BUILD_DEPENDS+=	${PYPKGPREFIX}-tox>=3.9.0:../../devel/py-tox
#BUILD_DEPENDS+=	# TODO: tox-travis>=0.12
#BUILD_DEPENDS+=	# TODO: pytest>=4.6.2
#BUILD_DEPENDS+=	# TODO: pytest-cov>=2.7.1
#BUILD_DEPENDS+=	# TODO: Sphinx>=2.2.1
#BUILD_DEPENDS+=	# TODO: sphinx-autobuild>=0.7.1
BUILD_DEPENDS+=	${PYPKGPREFIX}-sphinx-rtd-theme>=0.4.3:../../textproc/py-sphinx-rtd-theme
#DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.4;sys_platform=='win32':../../comms/py-colorama
#DEPENDS+=	${PYPKGPREFIX}-aiocontextvars>=0.2.0;python_version<'3.7':../../devel/py-aiocontextvars
#DEPENDS+=	# TODO: win32-setctime>=1.0.0;sys_platform=='win32'

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
