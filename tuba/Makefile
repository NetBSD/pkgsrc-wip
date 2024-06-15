# $NetBSD$

DISTNAME=	Tuba-0.7.2
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=GeopJr/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GeopJr/Tuba/
COMMENT=	Mastodon browser
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
