# $NetBSD: Makefile,v 1.2 2012/01/30 06:34:53 noud4 Exp $
#

DISTNAME=	mocker-0.10.1
PKGNAME=	${PYPKGPREFIX}-mocker-0.10.1
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://launchpad.net/mocker/trunk/0.10.1/+download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://labix.org/mocker
COMMENT=	Graceful platform for test doubles in Python
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

PYDISTUTILSPKG= yes
PY_PATCHPLIST=		yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
