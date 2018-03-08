# $NetBSD$

DISTNAME=	pkgbase-1.0
CATEGORIES=	pkgtools
HG_REPO=	${.CURDIR}/files/repo/pkgbase

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://www.pkgsrc.org/
COMMENT=	Test for Mercurial with a single repository
LICENSE=	2-clause-bsd

NO_CHECKSUM=	yes

.include "../../wip/mk/hg-package.mk"
.include "../../mk/bsd.pkg.mk"
