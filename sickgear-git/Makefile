# $NetBSD$

DISTNAME=	SickGear
PKGNAME=	sickgear-0
CATEGORIES=	multimedia

COMMENT=	Management of TV shows and/or Anime
LICENSE=	gnu-gpl-v3
HOMEPAGE=	https://github.com/SickGear/SickGear
MAINTAINER=	js-pkgsrc@nil.im

GIT_REPOSITORIES=	SickGear
GIT_REPO.SickGear=	https://github.com/SickGear/SickGear.git

DEPENDS+=	${PYPKGPREFIX}-cheetah-[0-9]*:../../devel/py-cheetah

PYTHON_VERSIONS_ACCEPTED=	27
REPLACE_PYTHON=			${WRKSRC}/sickgear.py

do-configure:

do-build:

do-install:
	mkdir -p ${DESTDIR}${PREFIX}/lib/sickgear
	cp -R ${WRKSRC}/* ${DESTDIR}${PREFIX}/lib/sickgear
	mkdir -p ${DESTDIR}${PREFIX}/bin
	${SED} ${FILES_SUBST_SED} ${FILESDIR}/sickgear \
		>${DESTDIR}${PREFIX}/bin/sickgear
	chmod 755 ${DESTDIR}${PREFIX}/bin/sickgear

.include "../../wip/mk/git-package.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
