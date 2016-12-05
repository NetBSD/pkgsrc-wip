# $NetBSD$

PKGNAME=	trelby-0
CATEGORIES=	editors
MASTER_SITES=	# defined

GIT_REPOSITORIES=	trelby
GIT_REPO.trelby=	https://github.com/oskusalerma/trelby.git

MAINTAINER=	cfkoch@edgebsd.org
COMMENT=	Screenplay writing program
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/trelby
USE_TOOLS+=	gzip

TRELBY_EXTRA_DATA=	# defined
TRELBY_EXTRA_DATA+=	names.txt.gz
TRELBY_EXTRA_DATA+=	dict_en.dat.gz

PYTHON_VERSIONS_ACCEPTABLE=	27
PYSETUPINSTALLARGS+=		--install-lib=${PREFIX}/${PYSITELIB}/trelby

# We don't want to have anything to do with the pre-hardcoded prefixes.
post-extract:
	${RM} -f ${WRKSRC}/setup.cfg

post-build:
.for target in ${TRELBY_EXTRA_DATA}
	${SETENV} ${MAKE_ENV} ${MAKE} -C ${WRKSRC} ${target}
.endfor

DEPENDS+=	py27-lxml>=3:../../textproc/py-lxml

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../lang/python/pyversion.mk"
#.include "../../x11/py-wxWidgets/buildlink3.mk" XXX wrong version
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
