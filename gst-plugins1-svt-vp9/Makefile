# $NetBSD$

DISTNAME=	svt-vp9-0.3.0
PKGNAME=	gst-plugins1-${DISTNAME}
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenVisualCloud/}
GITHUB_PROJECT=	SVT-VP9
GITHUB_TAG=	v{PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OpenVisualCloud/SVT-VP9/
COMMENT=	Open source multimedia framework - gstreamer svt-vp9 plugin
LICENSE=	modified-bsd

USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}/gstreamer-plugin
USE_CMAKE=	yes

.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../wip/svt-vp9/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
