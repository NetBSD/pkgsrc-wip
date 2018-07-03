# $NetBSD: Makefile,v 1.6 2014/05/09 07:38:45 thomasklausner Exp $

DISTNAME=	biskit-2.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	biology python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=biskit/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://biskit.pasteur.fr/
COMMENT=	Python platform for structural bioinformatics
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-biggles>=1.6.3:../../graphics/py-biggles
DEPENDS+=	${PYPKGPREFIX}-Scientific>=2.8:../../math/py-Scientific
DEPENDS+=	${PYPKGPREFIX}-rlcompleter2>=0.96:../../wip/py-rlcompleter2
DEPENDS+=	${PYPKGPREFIX}-readline>=0nb2:../../devel/py-readline

USE_TOOLS+=	perl
USE_LANGUAGES=	# none

REPLACE_PERL+=		Biskit/data/spectrum.pl
REPLACE_PYTHON+=	scripts/Biskit/bis2.6 Biskit/data/pdb/remediator_python.1.56.080328.py

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # py-Numeric

post-extract:
	${MV} ${WRKSRC}/scripts/Biskit/bis.py ${WRKSRC}/scripts/Biskit/bis${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../math/py-Numeric/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
