# $NetBSD$

DISTNAME=	volctl-0.8.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=buzz/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://buzz.github.io/volctl/
COMMENT=	System tray applet for Pulseaudio
LICENSE=	gnu-gpl-v2

GITHUB_TAG=	v${PKGVERSION_NOREV}

DEPENDS+=	${PYPKGPREFIX}-click-[0-9]*:../../devel/py-click
DEPENDS+=	${PYPKGPREFIX}-cairo-[0-9]*:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

WRKSRC=		${WRKDIR}/volctl-0.8.2
USE_LANGUAGES=	# none

EGG_NAME=	${PKGNAME_NOREV}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../mk/bsd.pkg.mk"
