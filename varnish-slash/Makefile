# $NetBSD$

DISTNAME=	slash-5725282989ef63d0ae0f2b9c53f4c8fb167e8991
PKGNAME=	varnish-slash-0.0.20230206
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITLAB:=uplex/varnish/slash/-/archive/5725282989ef63d0ae0f2b9c53f4c8fb167e8991/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/uplex/varnish/slash
COMMENT=	Storage Engines for Varnish-Cache
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=		autoconf-archive-[0-9]*:../../devel/autoconf-archive
TOOL_DEPENDS+=		${PYPKGPREFIX}-docutils>=0.12:../../textproc/py-docutils

USE_LIBTOOL=		yes
USE_TOOLS+=		aclocal autoconf automake gmake m4 pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		RST2MAN=${PREFIX}/bin/rst2man-${PYVERSSUFFIX}
CONFIGURE_ENV+=		VARNISHSRC=${VARNISHSRC}

VARNISHSRC=			${WRKOBJDIR}/www/varnish/work/varnish-7.2.1
BUILDLINK_PASSTHRU_DIRS+=	${VARNISHSRC}

LIBS.NetBSD+=		-lcurses

.include "../../mk/bsd.prefs.mk"

${VARNISHSRC}:
	cd ../../www/varnish && ${RECURSIVE_MAKE} build

pre-configure: ${VARNISHSRC}
	cd ${WRKSRC} && ./bootstrap

.include "../../lang/python/tool.mk"
.include "../../www/varnish/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
