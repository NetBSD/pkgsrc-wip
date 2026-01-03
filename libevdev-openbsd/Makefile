# $NetBSD$

DISTNAME=	libevdev-openbsd-20231111
CATEGORIES=	devel
MASTER_SITES=	https://code.tetaneutral.net/mherrb/libevdev-openbsd/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.tetaneutral.net/mherrb/libevdev-openbsd/
COMMENT=	Minimal set of libevdev functions for Wayland on OpenBSD/NetBSD
LICENSE=	mit

#NO_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/libevdev-openbsd

PKGCONFIG_OVERRIDE+=		libevdev.pc.in
#PKGCONFIG_OVERRIDE_STAGE=	pre-install

INSTALL_TARGET=		install  install-includes
INSTALLATION_DIRS+=	lib/pkgconfig
MAKE_ENV+=		INSTALL_DATA=${INSTALL_DATA:Q}

# nothing to configure but PKGCONFIG_OVERRIDE to apply
do-configure:
	@${DO_NADA}

.include "../../wip/libinput-bsd-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
