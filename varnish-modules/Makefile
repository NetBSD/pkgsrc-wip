# $NetBSD$

GITHUB_PROJECT=	varnish-modules
DISTNAME=	varnish-modules-0.19.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=varnish/}

MAINTAINER=	sasha-pkgsrc@arcocene.org
HOMEPAGE=	https://github.com/varnish/varnish-modules/
COMMENT=	Collection of modules extending Varnish VCL
LICENSE=	2-clause-bsd

BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils

USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf automake gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		RST2MAN=${PREFIX}/bin/rst2man-${PYVERSSUFFIX}

# not signed/unsigned char safe
BUILDLINK_TRANSFORM+=	rm:-Werror

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include "../../www/varnish/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
