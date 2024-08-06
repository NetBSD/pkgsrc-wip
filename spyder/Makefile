# $NetBSD$

DISTNAME=	spyder-5.4.0
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spyder/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://pypi.org/project/spyder/
COMMENT=	Scientific Python Development Environment
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pickleshare>=0.4:../../databases/py-pickleshare
DEPENDS+=	${PYPKGPREFIX}-jedi>=0.17.2:../../editors/py-jedi
DEPENDS+=	${PYPKGPREFIX}-chardet>=2.0.0:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-atomicwrites>=1.4.1:../../devel/py-atomicwrites
DEPENDS+=	${PYPKGPREFIX}-ipython>=6.5:../../devel/py-ipython
DEPENDS+=	${PYPKGPREFIX}-cloudpickle>=2.2.0:../../converters/py-cloudpickle
DEPENDS+=	${PYPKGPREFIX}-cookiecutter>=2.1.1:../../devel/py-cookiecutter
DEPENDS+=	${PYPKGPREFIX}-pylint>=2.5.0:../../devel/py-pylint
DEPENDS+=	${PYPKGPREFIX}-pyls-spyder>=0.4.0:../../wip/py-pyls-spyder
DEPENDS+=	${PYPKGPREFIX}-lsp-server>=1.5.0:../../lang/py-lsp-server
DEPENDS+=	${PYPKGPREFIX}-lsp-black>=1.2.1:../../wip/py-lsp-black
DEPENDS+=	${PYPKGPREFIX}-spyder-kernels>=2.4.0:../../wip/py-spyder-kernels
DEPENDS+=	${PYPKGPREFIX}-textdistance>=4.2.0:../../wip/py-textdistance
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.15.1:../../math/py-scipy
DEPENDS+=	${PYPKGPREFIX}-intervaltree-[0-9]*:../../devel/py-intervaltree
DEPENDS+=	${PYPKGPREFIX}-jellyfish-[0-9]*:../../textproc/py-jellyfish
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.16.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-numpydoc-[0-9]*:../../textproc/py-numpydoc
DEPENDS+=	${PYPKGPREFIX}-parso-[0-9]*:../../lang/py-parso
DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
DEPENDS+=	${PYPKGPREFIX}-psutil>=5.9.2:../../sysutils/py-psutil
DEPENDS+=	${PYPKGPREFIX}-xdg-[0-9]*:../../devel/py-xdg
DEPENDS+=	${PYPKGPREFIX}-diff-match-patch-[0-9]*:../../textproc/py-diff-match-patch
DEPENDS+=	${PYPKGPREFIX}-qtawesome>=1.2.1:../../wip/py-qtawesome
DEPENDS+=	${PYPKGPREFIX}-qtconsole>=5.3.2:../../wip/py-qtconsole
DEPENDS+=	${PYPKGPREFIX}-sphinx>=0.6.6:../../textproc/py-sphinx
DEPENDS+=	${PYPKGPREFIX}-three-merge>=0.1.1:../../wip/py-three-merge
DEPENDS+=	${PYPKGPREFIX}-qdarkstyle>=3.0.2:../../wip/py-qdarkstyle
DEPENDS+=	${PYPKGPREFIX}-qstylizer>=0.2.2:../../wip/py-qstylizer
DEPENDS+=	${PYPKGPREFIX}-rtree>=0.9.7:../../wip/py-rtree
DEPENDS+=	${PYPKGPREFIX}-pygments>=2.3.1:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-zmq>=23.2.1:../../net/py-zmq
DEPENDS+=	${PYPKGPREFIX}-paramiko>=2.11.0:../../security/py-paramiko
DEPENDS+=	${PYPKGPREFIX}-watchdog>=0.10.4:../../sysutils/py-watchdog
DEPENDS+=	${PYPKGPREFIX}-rtree>=1.0.1:../../wip/py-rtree
DEPENDS+=	${PYPKGPREFIX}-nbconvert-[0-9]*:../../www/py-nbconvert
DEPENDS+=	${PYPKGPREFIX}-pylint-venv>=2.1.1:../../wip/py-pylint-venv

USE_TOOLS+=	bash

REPLACE_BASH+=	spyder/plugins/ipythonconsole/scripts/conda-activate.sh
REPLACE_BASH+=	spyder/utils/check-git.sh

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-qt5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
