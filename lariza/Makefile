# $NetBSD$

PKGNAME=	lariza-18.03
GITHUB_PROJECT=	lariza
DISTNAME=	${GITHUB_TAG}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=vain/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.uninformativ.de/projects/lariza/
COMMENT=	Experimental web browser using WebKit2GTK+
LICENSE=	mit

WRKSRC=	${WRKDIR}/${PKGNAME_NOREV}

USE_TOOLS+=		gmake pkg-config
INSTALL_MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}
INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}

.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
