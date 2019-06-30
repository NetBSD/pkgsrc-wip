# $NetBSD: Makefile,v 1.2 2014/02/17 01:09:19 othyro Exp $
#

DISTNAME=	0.3
PKGNAME=	uprof-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	https://github.com/rib/UProf/archive/
DIST_SUBDIR=	${PKGBASE}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rib/UProf
COMMENT=	Toolkit for profiling applications in a domain-specific way
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/UProf-${DISTNAME}
USE_TOOLS+=	aclocal autoconf autoheader automake gawk gm4 gsed pkg-config
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE+=	uprof.pc.in

.include "options.mk"

.if ${OPSYS} != "Linux"
BUILDLINK_TRANSFORM=	rm:-ldl
.endif

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${SH} autogen.sh

.include "../../mk/dlopen.buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
BUILD_DEPENDS+=	gnome-common-[0-9]*:../../devel/gnome-common
.include "../../mk/bsd.pkg.mk"
