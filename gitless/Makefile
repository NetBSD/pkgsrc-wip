# $NetBSD$

DISTNAME=	gitless-0.8.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=sdg-mit/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gitless.com/
COMMENT=	Experimental version control system built on top of Git
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-clint>=0.3.6:../../devel/py-clint
DEPENDS+=	${PYPKGPREFIX}-pygit2>=0.23.0:../../wip/py-pygit2
DEPENDS+=	${PYPKGPREFIX}-git-[0-9]*:../../wip/py-git
DEPENDS+=	${PYPKGPREFIX}-sh>=1.11:../../wip/py-sh

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} gl gl-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
