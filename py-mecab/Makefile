# $NetBSD: Makefile,v 1.1.1.1 2006/03/19 13:55:31 obache Exp $
#

.include "../../wip/mecab/Makefile.common"

DISTNAME=	mecab-python-${MECAB_VERSION}
PKGNAME=	${PYPKGPREFIX}-mecab-${MECAB_VERSION}
CATEGORIES=	japanese textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=mecab/19396/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://mecab.sourceforge.jp/
COMMENT=	MeCab python module

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

do-test:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}			\
	cd ${WRKSRC};							\
	${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../wip/mecab/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
