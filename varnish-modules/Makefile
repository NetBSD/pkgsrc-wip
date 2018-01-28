# $NetBSD$

GITHUB_PROJECT=	varnish-modules
DISTNAME=	0.12.1
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=varnish/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	sasha-pkgsrc@arcocene.org
HOMEPAGE=	https://github.com/varnish/varnish-modules/
COMMENT=	Collection of modules extending Varnish VCL
LICENSE=	2-clause-bsd

WRKSRC=	${WRKDIR}/varnish-modules-0.12.1

DEPENDS+=	varnish>=4.1.4:../../wip/varnish
BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_TOOLS+=		automake
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-rst2man=${PREFIX}/bin/rst2man-${PYVERSSUFFIX}.py

pre-configure:
	cd ${WRKSRC} && ./bootstrap

.include "../../wip/varnish/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mgcc)
DEPENDS+=       ${_GCC_DEPENDENCY}
.endif
