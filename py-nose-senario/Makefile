# $NetBSD: Makefile,v 1.1.1.1 2009/06/17 23:19:45 jihbed Exp $
#

DISTNAME=	nose_scenario-0.1.3.tar
PKGNAME=	${PYPKGPREFIX}-nose-scenario-0.1.3
CATEGORIES=	devel python
MASTER_SITES=	http://pypi.python.org/packages/source/n/nose_scenario/
EXTRACT_SUFX=	.gz

MAINTAINER=	kamelderouiche@yahoo.com
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
