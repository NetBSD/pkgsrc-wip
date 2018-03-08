# $NetBSD$

DISTNAME=	pkgbase-1.0
CATEGORIES=	pkgtools
CVS_ROOT=	${.CURDIR}/files/repo

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://www.pkgsrc.org/
COMMENT=	Test for CVS with a single repository
LICENSE=	2-clause-bsd

NO_CHECKSUM=	yes

.include "../../wip/mk/cvs-package.mk"
.include "../../mk/bsd.pkg.mk"
