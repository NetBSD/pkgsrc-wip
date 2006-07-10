# $NetBSD: Makefile,v 1.5 2006/07/10 16:23:17 obache Exp $
#

.include "../../wip/mecab/Makefile.common"

DISTNAME=	mecab-python-${MECAB_VERSION}
PKGNAME=	${PYPKGPREFIX}-mecab-${MECAB_VERSION}
CATEGORIES=	japanese textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=mecab/20921/}

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://mecab.sourceforge.jp/
COMMENT=	MeCab python module

USE_LANGUAGES+=	c++

PYDISTUTILSPKG=	yes
PYBINMODULE=	yes

do-test:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}			\
	cd ${WRKSRC};							\
	${SETENV} ${TEST_ENV} ${PYTHONBIN} test.py

.include "../../wip/mecab/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
