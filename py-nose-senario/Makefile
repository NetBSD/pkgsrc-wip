# $NetBSD: Makefile,v 1.2 2010/06/04 12:05:51 jihbed Exp $
#

DISTNAME=	nose_scenario-0.1.3.tar
PKGNAME=	${PYPKGPREFIX}-nose-scenario-0.1.3
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/n/nose_scenario/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://cheeseshop.python.org/pypi/nose_scenario/
COMMENT=	Nose plugin test unittest scenario adapt
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-nose-[0-9]:../../wip/py-nose

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/nose_scenario-0.1.3
USE_LANGUAGES=	# none

PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX:Q}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
