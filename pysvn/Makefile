# $NetBSD: Makefile,v 1.1.1.1 2010/08/13 14:53:47 helgoman Exp $
#

VERS=				1.7.2
DISTNAME=			pysvn-${VERS}
PKGNAME=			${PYPKGPREFIX}-pysvn-${VERS}
CATEGORIES=			devel
MASTER_SITES=		http://pysvn.barrys-emacs.org/source_kits/

MAINTAINER=			helgoman@users.sourceforge.net
HOMEPAGE=			http://pysvn.tigris.org/
COMMENT=			Python interface to Subversion
LICENSE=			apache-1.1

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=			${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
WRKSRC=				${WRKDIR}/${DISTNAME}/Source
TESTDIR=			${WRKDIR}/${DISTNAME}/Tests

USE_LANGUAGES=		c c++

PYSETUP=			setup.py
PYSETUPSUBDIR=		pysvn
PY_PATCHPLIST=		yes

.include "../../lang/python/pyversion.mk"

do-configure:
.if ${PYVERSSUFFIX} == "2.5" || ${PYVERSSUFFIX} == "2.4"
	cd ${WRKSRC} && ${PYTHONBIN} ${PYSETUP} backport
.endif
	cd ${WRKSRC} && ${PYTHONBIN} ${PYSETUP} configure

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${PYSITELIB}/pysvn
	${INSTALL_DATA} \
	${WRKSRC}/${PYSETUPSUBDIR}/*.py \
	${WRKSRC}/${PYSETUPSUBDIR}/*.so \
	${DESTDIR}${PREFIX}/${PYSITELIB}/pysvn

do-test:
	cd ${WRKSRC}/${TESTDIR} && ${MAKE}

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
