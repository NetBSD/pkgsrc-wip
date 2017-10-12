# $NetBSD: Makefile,v 1.2 2012/10/07 11:54:31 asau Exp $
#

DISTNAME=	firehose-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=f/firehose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fedora-static-analysis/firehose
COMMENT=	Library for managing code analysis tool output
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		# none

TEST_TARGET=	unittests

DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

SUBST_CLASSES+=			python
SUBST_STAGE.python=		pre-test
SUBST_MESSAGE.python=		Fixing python binary for test
SUBST_FILES.python=		Makefile
SUBST_SED.python=		-e 's,python ,${PYTHONBIN} ,g'


.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
