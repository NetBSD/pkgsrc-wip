# $NetBSD: Makefile,v 1.2 2014/06/01 12:49:38 thomasklausner Exp $

DISTNAME=	adsbibdesk-3.1.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_PYPI:=a/adsbibdesk/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.jonathansick.ca/adsbibdesk/
COMMENT=	Add papers from arxiv.org or NASA/SAO ADS to your BibDesk bibliography
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_SED.paths+=	-e 's,/usr/bin/python,${PREFIX}/bin/python${PYVERSSUFFIX},g'
SUBST_FILES.paths+=	adsbibdesk.py
SUBST_MESSAGE.paths=	Fixing header search paths.

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
