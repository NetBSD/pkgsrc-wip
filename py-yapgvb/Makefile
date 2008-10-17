# $NetBSD: Makefile,v 1.1 2008/10/17 16:05:34 marko_schuetz Exp $
#

DISTNAME=	yapgvb-1.1.3
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=yapgvb/}

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	${MASTER_SITE_SOURCEFORGE:=yapgvb/}
COMMENT=	Yapgvb is a shiny new way to use python and graphviz at the same time

SUBST_CLASSES+=                 fix-paths
SUBST_STAGE.fix-paths=          pre-configure
SUBST_MESSAGE.fix-paths=        Fixing absolute paths.
SUBST_FILES.fix-paths=          config_unix.py
SUBST_SED.fix-paths=            -e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-paths+=           -e 's,/usr/include,${PREFIX}/include,g'
SUBST_SED.fix-paths+=           -e 's,/usr/lib,${PREFIX}/lib,g'
SUBST_SED.fix-paths+=           -e 's,boost_python,boost_python-mt,g'


PYDISTUTILSPKG=	yes

WRKSRC=		${WRKDIR}/yapgvb
USE_LANGUAGES=	c c++

.include "../../devel/boost-python/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
