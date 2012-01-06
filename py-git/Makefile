# $NetBSD: Makefile,v 1.1.1.1 2012/01/06 11:19:04 jihbed Exp $
#

DISTNAME=	GitPython-0.3.2.RC1
PKGNAME=	${PYPKGPREFIX}-git-0.3.2.rc1
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/G/GitPython/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://gitorious.org/projects/git-python/
COMMENT=	Python library used to interact with Git repositories
LICENSE=	modified-bsd

#DEPENDS+=	${PYPKGPREFIX}-gitdb>=0.6.1:../../wip/py-gitdb

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/GitPython-0.3.2.RC1

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
