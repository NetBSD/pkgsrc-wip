# $NetBSD$

GITHUB_PROJECT=	oksh
GITHUB_TAG=	OpenBSD-6.3
DISTNAME=       ${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-${GITHUB_TAG}
CATEGORIES=	wip
MASTER_SITES=	${MASTER_SITE_GITHUB:=ibara/}
DIST_SUBDIR=	${PKGNAME}

MAINTAINER=	pkgsrc-users@pkgsrc.org
HOMEPAGE=	https://github.com/ibara/oksh/
COMMENT=	Portable OpenBSD ksh(1)
WRKSRC=		${WRKDIR}/${PKGNAME}
LICENSE=	original-bsd

GNU_CONFIGURE=          yes

.include "../../mk/bsd.pkg.mk"
