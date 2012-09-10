# $NetBSD: Makefile,v 1.5 2012/09/10 09:22:59 jihbed Exp $
#

DISTNAME=	django-gitrevision-0.1.4
EGG_NAME=	${DISTNAME:S|o-|o_|:Q}
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/d/django-gitrevision/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://github.com/klen/django-gitrevision.git
COMMENT=	Django git revision
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-django-[0-9]*:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-git-[0-9]*:../../wip/py-git

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/django-gitrevision-0.1.4

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED= 31 27 26 25

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
