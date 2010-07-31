# $NetBSD: Makefile,v 1.1.1.1 2010/07/31 12:08:02 jihbed Exp $
#

DISTNAME=	AOPython-1.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/AOP/aop/}
CATEGORIES=	devel
MASTER_SITES=	http://pypi.python.org/packages/source/A/AOPython/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://pieces.openpolitics.com/?s=AOPython
COMMENT=	Aspect Oriented Python
LICENSE=	python-software-foundation

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
PYDISTUTILSPKG=	yes

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
