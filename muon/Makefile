# $NetBSD$

PKGNAME=	muon-0.1.0
DISTNAME=	${PKGNAME:S/muon-//}
CATEGORIES=	devel
MASTER_SITES=	https://git.sr.ht/~lattis/muon/archive/

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~lattis/muon
COMMENT=	Implementation of meson build system in c99 with minimal dependencies
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c99

TOOL_DEPENDS+=	samurai>=1.2:../../devel/samurai

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
INSTALLATION_DIRS=	bin

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} \
		${CONFIG_SHELL} ./bootstrap.sh bootstrap1
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ./bootstrap1/muon setup -Ddocs=disabled -Dstatic=false -Dlibcurl=disabled -Dlibarchive=disabled bootstrap2
	cd ${WRKSRC} && env ${CONFIGURE_ENV} samu -C bootstrap2

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} ./bootstrap2/muon setup -Ddocs=disabled -Dstatic=false -Dlibcurl=disabled -Dlibarchive=disabled output
	cd ${WRKSRC} && env ${MAKE_ENV} samu -C output

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/muon \
		${DESTDIR}${PREFIX}/bin/muon

# Note: pkgconf library is included via hacks.mk
#.include "../../archivers/libarchive/buildlink3.mk"
#.include "../../www/curl/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
