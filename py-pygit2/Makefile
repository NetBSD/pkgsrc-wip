# $NetBSD: Makefile,v 1.6 2014/12/04 23:44:45 othyro Exp $

DISTNAME=	pygit2-0.21.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pygit2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libgit2/pygit2
COMMENT=	Python bindings to libgit2
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-cffi-[0-9]*:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-cparser-[0-9]*:../../devel/py-cparser

USE_LANGUAGES=	c
PY_PATCHPLIST=	yes

#do-install:
#	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PYTHONBIN} setup.py install --root=${DESTDIR} --prefix=${PREFIX}

.include "../../devel/libgit2/buildlink3.mk"
.include "../../lang/python/distutils.mk"
#.include "../../lang/python/application.mk"
#.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
