# $NetBSD$

GITHUB_PROJECT=	gtkada
GITHUB_TAG=	v21.0.0
DISTNAME=	v21.0.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=AdaCore/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/gtkada/
COMMENT=	Ada graphical toolkit based on gtk
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/gtkada-21.0.0
GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
