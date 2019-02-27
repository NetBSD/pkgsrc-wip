# $NetBSD$

DISTNAME=	guile-commonmark-0.1.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=OrangeShark/}
GITHUB_RELEASE=	v0.1.2

MAINTAINER=	ng0@n0.is
HOMEPAGE=	https://github.com/OrangeShark/guile-commonmark/
COMMENT=	Implementation of CommonMark for Guile
LICENSE=	gnu-lgpl-v3
USE_TOOLS+=	pkg-config

GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/guile/2.2
CONFIGURE_ARGS+=	--libdir=${PREFIX}/guile/2.2/lib

.include "../../lang/guile22/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
