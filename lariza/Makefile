# $NetBSD$

PKGNAME=	lariza-21.01
PKGREVISION=	# override since GIT_TAG gives the version
CATEGORIES=	www
GIT_REPO=	https://www.uninformativ.de/git/lariza.git
GIT_TAG=	v21.01

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://uninformativ.de/git/lariza
COMMENT=	Experimental web browser using WebKit2GTK+
LICENSE=	mit

USE_TOOLS+=		gmake pkg-config
INSTALL_MAKE_FLAGS+=	mandir=${PREFIX}/${PKGMANDIR}
INSTALL_MAKE_FLAGS+=	prefix=${PREFIX}

.include "../../wip/mk/git-package.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
