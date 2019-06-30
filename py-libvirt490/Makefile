# $NetBSD: Makefile,v 1.32 2018/11/30 09:59:40 adam Exp $

DISTNAME=	libvirt-python-4.9.0
CATEGORIES=	sysutils python
MASTER_SITES=	https://libvirt.org/sources/python/

MAINTAINER=	andyb@m42.one
HOMEPAGE=	https://libvirt.org/sources/python/
COMMENT=	libvirt python library
LICENSE=	gnu-lgpl-v2

#DEPENDS+=	${PYPKGPREFIX}-backcall-[0-9]*:../../devel/py-backcall
#DEPENDS+=	${PYPKGPREFIX}-decorator-[0-9]*:../../devel/py-decorator
#DEPENDS+=	${PYPKGPREFIX}-jedi>=0.10:../../editors/py-jedi
#DEPENDS+=	${PYPKGPREFIX}-pexpect-[0-9]*:../../devel/py-pexpect
#DEPENDS+=	${PYPKGPREFIX}-pickleshare-[0-9]*:../../databases/py-pickleshare
#DEPENDS+=	${PYPKGPREFIX}-prompt_toolkit>=2.0.0:../../devel/py-prompt_toolkit2
#DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
#DEPENDS+=	python37-[0-9]*:../../lang/python37
DEPENDS+=	${PYPKGPREFIX}-setuptools>=18.5:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-simplegeneric>0.8:../../devel/py-simplegeneric
#DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3
#DEPENDS+=	${PYPKGPREFIX}-traitlets>=4.2:../../devel/py-traitlets

USE_LANGUAGES=	# none
#REPLACE_PYTHON=
#PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 37
DEPENDS+=	${PYPKGPREFIX}-typing-[0-9]*:../../devel/py-typing
.endif

#post-install:
#	cd ${DESTDIR}${PREFIX} && \
#	${RM} bin/iptest3 bin/ipython3 && \
#	${MV} bin/iptest bin/iptest-${PYVERSSUFFIX} && \
#	${MV} bin/ipython bin/ipython-${PYVERSSUFFIX} && \
#	${MV} ${PKGMANDIR}/man1/ipython.1 ${PKGMANDIR}/man1/ipython-${PYVERSSUFFIX}.1 || ${TRUE}

#.include "../../lang/python/distutils.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
