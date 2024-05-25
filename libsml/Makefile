# $NetBSD: $

DISTNAME=	libsml-1.1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=volkszaehler/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	mp@petermann-it.de
HOMEPAGE=	https://github.com/volkszaehler/libsml
COMMENT=	Smart Message Language (SML) protocol
LICENSE=	gnu-gpl-v3

USE_LIBTOOL=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	gmake

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_FILES.paths=	sml/Makefile
SUBST_FILES.paths+=	examples/Makefile
SUBST_VARS.paths=	PREFIX

.include "../../mk/bsd.prefs.mk"

.include "../../devel/libuuid/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
