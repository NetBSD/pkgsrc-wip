# $NetBSD$

GITHUB_PROJECT=	git-multimail
GITHUB_TAG=	1.5.0
DISTNAME=	1.5.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_GITHUB:=git-multimail/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/git-multimail/git-multimail
COMMENT=	Send notification emails for Git pushes
#LICENSE=	GPLv2 # TODO: from setup.py; needs to be adjusted

WRKSRC=		${WRKDIR}/git-multimail-1.5.0
USE_LANGUAGES=	# none

# TODO: Migrate MASTER_SITES to MASTER_SITE_PYPI
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
