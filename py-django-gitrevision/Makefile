# $NetBSD: Makefile,v 1.1.1.1 2012/01/06 11:35:47 jihbed Exp $
#

DISTNAME=	django-gitrevision-0.1.4
EGG_NAME=	django_gitrevision
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-gitrevision/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://github.com/klen/django-gitrevision.git
COMMENT=	TODO: Short description of the package
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-git-[0-9]:../../wip/py-git

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/django-gitrevision-0.1.4

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 31 27 26 25

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
