# $NetBSD$

PKGNAME=		muon-0.3.0
DISTNAME=		${PKGNAME:S/muon-//}
CATEGORIES=		devel
MASTER_SITES=		https://git.sr.ht/~lattis/muon/archive/
DIST_SUBDIR=		${PKGNAME_NOREV}
DISTFILES=		${DEFAULT_DISTFILES} man.tar.gz
SITES.man.tar.gz=	https://muon.build/releases/v${DISTNAME}/docs/

MAINTAINER=	micha@NetBSD.org
HOMEPAGE=	https://git.sr.ht/~lattis/muon
COMMENT=	Implementation of meson build system in C99 with minimal dependencies
LICENSE=	gnu-gpl-v3

USE_CC_FEATURES=	c99

CFLAGS+=		-DBOOTSTRAP_NO_SAMU
TOOL_DEPENDS+=		samurai>=1.2:../../devel/samurai

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} \
		${CONFIG_SHELL} ./bootstrap.sh bootstrap1
	cd ${WRKSRC} && env ${CONFIGURE_ENV} ./bootstrap1/muon setup \
		-Dlibcurl=disabled \
		-Dlibarchive=disabled \
		-Dlibpkgconf=enabled \
		-Dsamurai=disabled \
		-Dreadline=builtin \
		-Dstatic=false \
		-Ddocs=disabled \
		-Dwebsite=false \
		-Dtracy=disabled \
		bootstrap2
	cd ${WRKSRC} && env ${CONFIGURE_ENV} \
		samu -j ${_MAKE_JOBS_N:U1} -C bootstrap2

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} ./bootstrap2/muon setup \
		-Dlibcurl=disabled \
		-Dlibarchive=disabled \
		-Dlibpkgconf=enabled \
		-Dsamurai=disabled \
		-Dreadline=builtin \
		-Dstatic=false \
		-Ddocs=disabled \
		-Dwebsite=false \
		-Dtracy=disabled \
		output
	cd ${WRKSRC} && env ${MAKE_ENV} \
		samu -j ${_MAKE_JOBS_N:U1} -C output

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/output/muon \
		${DESTDIR}${PREFIX}/bin/muon
	${INSTALL_MAN} ${WRKDIR}/man/muon.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/pkgconf/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
