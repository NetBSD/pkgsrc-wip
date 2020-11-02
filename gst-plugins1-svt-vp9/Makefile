# $NetBSD$

GITHUB_PROJECT=	SVT-VP9
GITHUB_TAG=	v0.3.0
DISTNAME=	v0.3.0
PKGNAME=	gst-plugins1-${GITHUB_PROJECT:tl}-${DISTNAME:S,^v,,}
CATEGORIES=	# TODO: add primary category
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenVisualCloud/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenVisualCloud/SVT-VP9/
COMMENT=	Open source multimedia framework - svt-vp9 plugin
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/SVT-VP9-0.3.0/gstreamer-plugin
USE_CMAKE=	yes

.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../wip/svt-vp9/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
