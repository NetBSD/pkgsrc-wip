# $NetBSD$

GITHUB_PROJECT=	doas
DISTNAME=	6.1
PKGNAME=	doas-6.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=slicer69/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/slicer69/doas/
COMMENT=	Allow others to run commands as root
LICENSE=	2-clause-bsd

USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/doas-6.1

#INSTALL_MAKE_FLAGS+=	PREFIX=${PREFIX:Q}

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
