# $NetBSD$

DISTNAME=	pkgbase-1.0
CATEGORIES=	pkgtools

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://www.pkgsrc.org/
COMMENT=	Test for Git with multiple repositories
LICENSE=	2-clause-bsd

NO_CHECKSUM=	yes

GIT_REPO=		${.CURDIR}/files/repo/pkgbase
GIT_REPOSITORIES=	2017 current
GIT_REPO.2017=		${GIT_REPO}
GIT_TAG.2017=		v2017
GIT_REPO.current=	${GIT_REPO}

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
