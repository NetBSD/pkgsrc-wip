# $NetBSD$

DISTNAME=	eyeD3-0.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eyeD3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://eyed3.nicfit.net/
COMMENT=	Python tool for working with audio files (in particular, mp3)
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=			# none
PYTHON_VERSIONS_ACCEPTED=	38 37 # dataclasses is required for 36, not in pkgsrc
REPLACE_SH+=			bin/eyeD3

DEPENDS+=	${PYPKGPREFIX}-filetype-[0-9]*:../../wip/py-filetype
DEPENDS+=	${PYPKGPREFIX}-deprecation-[0-9]*:../../devel/py-deprecation

SUBST_CLASSES+=		python
SUBST_STAGE.python=	post-configure
SUBST_MESSAGE.python=	Fixing path to python executable.
SUBST_FILES.python+=	bin/eyeD3
SUBST_SED.python+=	-e "s,python,${PYTHONBIN},"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
