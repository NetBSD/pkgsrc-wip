# $NetBSD: Makefile,v 1.1 2015/03/09 22:51:10 tnn2 Exp $

DISTNAME=	libepoxy-1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=anholt/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/anholt/libepoxy/
COMMENT=	Library for OpenGL function pointer management
LICENSE=	mit

USE_TOOLS+=	pkg-config autoreconf automake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
PYTHON_FOR_BUILD_ONLY=	yes

PKGCONFIG_OVERRIDE+=	epoxy.pc.in

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

.include "../../lang/python/tool.mk"
BUILDLINK_API_DEPENDS.MesaLib+=	MesaLib>=10
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
