# $NetBSD$

DISTNAME=	pkgbase-1.0
CATEGORIES=	pkgtools
SVN_REPO=	file://${.CURDIR}/files/repo/pkgbase/trunk

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://www.pkgsrc.org/
COMMENT=	Test for Subversion with a single repository
LICENSE=	2-clause-bsd

NO_CHECKSUM=	yes

.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
