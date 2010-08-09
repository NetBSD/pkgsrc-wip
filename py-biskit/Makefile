# $NetBSD: Makefile,v 1.1.1.1 2010/08/09 21:40:36 jihbed Exp $
#

DISTNAME=	biskit-2.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=biskit/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://biskit.pasteur.fr/
COMMENT=	Python platform for structural bioinformatics
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-biggles>=1.6.3:../../graphics/py-biggles
DEPENDS+=	${PYPKGPREFIX}-Scientific>=2.8:../../math/py-Scientific
DEPENDS+=	${PYPKGPREFIX}-rlcompleter2>=0.96:../../wip/py-rlcompleter2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	perl
USE_LANGUAGES=	# none

REPLACE_PERL+=	Biskit/data/spectrum.pl
REPLACE_PYTHON+=	scripts/Biskit/bis2.6 Biskit/data/pdb/remediator_python.1.56.080328.py

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=		yes
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}


post-extract:
	${MV} ${WRKSRC}/scripts/Biskit/bis.py ${WRKSRC}/scripts/Biskit/bis${PYVERSSUFFIX}

.include "../../devel/py-readline/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
