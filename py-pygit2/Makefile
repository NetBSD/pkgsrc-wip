# $NetBSD: Makefile,v 1.1 2013/01/02 18:49:45 othyro Exp $
#

DISTNAME=	v0.17.3
PKGNAME=	${PYPKGPREFIX}-pygit2-${DISTNAME:S/v//1}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libgit2/pygit2/archive/
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/libgit2/pygit2
COMMENT=	Python bindings to libgit2
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV:S/${PYPKGPREFIX}-//1}

PYTHON_VERSIONS_ACCEPTED=	32 31 27 26
PY_PATCHPLIST=			yes

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} setup.py build

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${PYTHONBIN} setup.py install --root=${DESTDIR} --prefix=${PREFIX}

.include "../../wip/libgit2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
