# $NetBSD: Makefile,v 1.10 2007/04/01 02:19:13 obache Exp $
#

.include "../../wip/mecab/Makefile.common"

DISTNAME=	mecab-python-${MECAB_VERSION}
PKGNAME=	${PYPKGPREFIX}-mecab-${MECAB_VERSION}
CATEGORIES=	japanese textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mecab/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mecab.sourceforge.net/
COMMENT=	MeCab python module

USE_LANGUAGES=	c c++

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

TEST_ENV+=	PYTHONPATH=${WRKSRC:Q}/build/lib.${LOWER_OPSYS}-${OS_VERSION}-${MACHINE_ARCH}-${PYVERSSUFFIX}

do-test:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}			\
	cd ${WRKSRC};							\
	${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../wip/mecab/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
