# $NetBSD$

DISTNAME=	pkgbase-1.0
CATEGORIES=	pkgtools
FOSSIL_REPO=	${.CURDIR}/files/repo/pkgbase.fossil

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://www.pkgsrc.org/
COMMENT=	Test for Fossil with a single repository
LICENSE=	2-clause-bsd

NO_CHECKSUM=	yes

.include "../../wip/mk/fossil-package.mk"
.include "../../mk/bsd.pkg.mk"
