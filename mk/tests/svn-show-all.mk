# $NetBSD$

DISTNAME=	pkgbase-1.0
CATEGORIES=	pkgtools

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://www.pkgsrc.org/
COMMENT=	Test for show-all-svn
LICENSE=	2-clause-bsd

NO_CHECKSUM=	yes

SVN_REPO=		file://${.CURDIR}/files/repo/pkgbase/trunk
SVN_REPOSITORIES=	2017 current
SVN_REPO.2017=		${SVN_REPO}
SVN_REVISION.2017=	1
SVN_REPO.current=	${SVN_REPO}

.include "../../wip/mk/svn-package.mk"
.include "../../mk/bsd.pkg.mk"
