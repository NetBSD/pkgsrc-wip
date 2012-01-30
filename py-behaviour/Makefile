# $NetBSD: Makefile,v 1.2 2012/01/30 05:57:06 noud4 Exp $
#

DISTNAME=	Behaviour-0.1a4.tar
PKGNAME=	${PYPKGPREFIX}-behaviour-0.1
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/B/Behaviour/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://pypi.python.org/pypi/Behaviour/
COMMENT=	Behaviour Driven Development in Python
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/Behaviour-0.1a4
USE_LANGUAGES=	# none
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
