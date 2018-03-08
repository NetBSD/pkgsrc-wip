# $NetBSD$

DISTNAME=	pkgbase-1.0
CATEGORIES=	pkgtools

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://www.pkgsrc.org/
COMMENT=	Test for Mercurial with multiple repositories
LICENSE=	2-clause-bsd

NO_CHECKSUM=	yes

HG_REPO=		${.CURDIR}/files/repo/pkgbase
HG_REPOSITORIES=	2017 current
HG_REPO.2017=		${HG_REPO}
HG_TAG.2017=		v2017
HG_REPO.current=	${HG_REPO}

.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
