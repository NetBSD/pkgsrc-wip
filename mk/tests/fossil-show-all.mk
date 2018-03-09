# $NetBSD$

DISTNAME=	pkgbase-1.0
CATEGORIES=	pkgtools

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://www.pkgsrc.org/
COMMENT=	Test for show-all-fossil
LICENSE=	2-clause-bsd

NO_CHECKSUM=	yes

FOSSIL_REPO=		${.CURDIR}/files/repo/pkgbase.fossil
FOSSIL_REPOSITORIES=	2017 current
FOSSIL_REPO.2017=	${FOSSIL_REPO}
FOSSIL_VERSION.2017=	v2017
FOSSIL_REPO.current=	${FOSSIL_REPO}

.include "../../wip/mk/fossil-package.mk"
.include "../../mk/bsd.pkg.mk"
