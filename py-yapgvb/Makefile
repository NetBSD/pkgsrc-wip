# $NetBSD: Makefile,v 1.2 2015/07/13 15:12:13 thomasklausner Exp $

DISTNAME=	yapgvb-1.2.3-source
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/-source//}
CATEGORIES=	graphics
MASTER_SITES=	https://yapgvb.googlecode.com/files/

MAINTAINER=	MarkoSchuetz@web.de
HOMEPAGE=	https://code.google.com/p/yapgvb/
COMMENT=	Yet Another Python Graphviz Binding
LICENSE=	modified-bsd

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		config_unix.py
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-paths+=		-e 's,/usr/include,${PREFIX}/include,g'
SUBST_SED.fix-paths+=		-e 's,/usr/lib,${PREFIX}/lib,g'
SUBST_SED.fix-paths+=		-e 's,boost_python,boost_python-mt,g'

USE_LANGUAGES=	c c++
EGG_NAME=	${DISTNAME:S/-source//}

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 1.2.3

.include "../../devel/py-boost/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
