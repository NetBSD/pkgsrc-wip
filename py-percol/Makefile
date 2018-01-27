# $NetBSD: Makefile,v 1.1 2013/09/11 05:10:05 phonohawk Exp $
#

DISTNAME=	percol-0.0.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	misc

MAINTAINER=	pho@cielonegro.org
HOMEPAGE=	https://github.com/mooz/percol
COMMENT=	Filter lines interactively in a pipeline
LICENSE=	mit

GIT_REPOSITORIES=	mooz
GIT_REPO.mooz=		git://github.com/mooz/percol.git
GIT_MODULE.mooz=	percol
WRKSRC=			${WRKDIR}/percol

SUBST_CLASSES+=		migemo
SUBST_STAGE.migemo=	pre-build
SUBST_MESSAGE.migemo=	Replacing path to the migemo dictionary
SUBST_FILES.migemo=	percol/finder.py
SUBST_VARS.migemo=	PREFIX

MESSAGE_SUBST+=	PYSITELIB=${PYSITELIB:Q}

post-install:
	${INSTALL_DATA} ${FILESDIR}/rc.py \
		${DESTDIR}${PREFIX}/${PYSITELIB}/percol/rc.py

DEPENDS+=	cmigemo-[0-9]*:../../textproc/cmigemo
DEPENDS+=	${PYPKGPREFIX}-curses-[0-9]*:../../devel/py-curses
DEPENDS+=	${PYPKGPREFIX}-pymigemo-[0-9]*:../../wip/py-pymigemo

.include "../../lang/python/distutils.mk"
.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
