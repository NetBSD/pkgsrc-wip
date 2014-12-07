# $NetBSD: Makefile,v 1.1 2014/12/07 00:19:03 jonthn Exp $

DISTNAME=	v1.10.2
PKGNAME=	livestreamer-${DISTNAME:C/v//1}
CATEGORIES=	multimedia python
MASTER_SITES=	https://github.com/chrippa/livestreamer/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://livestreamer.tanuki.se/
COMMENT=	Tool that pipes video streams into a video player
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests

.include "../../lang/python/extension.mk"

.if ${_PYTHON_VERSION} == 26
DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
.endif
.if ${_PYTHON_VERSION} < 30
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-futures-[0-9]*:../../wip/py-futures
.endif
.if ${_PYTHON_VERSION} <= 33
DEPENDS+=	${PYPKGPREFIX}-singledispatch-[0-9]*:../../wip/py-singledispatch
.endif

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

REPLACE_PYTHON+= src/livestreamer/packages/flashmedia/flv.py
REPLACE_PYTHON+= src/livestreamer/packages/flashmedia/tag.py
REPLACE_PYTHON+= src/livestreamer/packages/flashmedia/__init__.py
REPLACE_PYTHON+= src/livestreamer/packages/flashmedia/packet.py
REPLACE_PYTHON+= src/livestreamer/packages/flashmedia/error.py
REPLACE_PYTHON+= src/livestreamer/packages/flashmedia/f4v.py
REPLACE_PYTHON+= src/livestreamer/packages/flashmedia/util.py

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
