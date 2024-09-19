# $NetBSD$

DISTNAME=	libnl-3.2.25
CATEGORIES=	devel
MASTER_SITES=	https://www.infradead.org/~tgr/libnl/files/

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://www.infradead.org/~tgr/libnl/
COMMENT=	APIs to netlink protocol based Linux kernel interfaces
LICENSE=	gnu-lgpl-v2.1

# Linux-specific library
ONLY_FOR_PLATFORM=	Linux-*-*

EGDIR=		${PREFIX}/share/examples/${PKGBASE}
CONFS=		classid pktloc
.for f in ${CONFS}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/libnl/${f}
.endfor

USE_TOOLS+=	gmake
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
.for f in ${CONFS}
	${MV} ${DESTDIR}${PREFIX}/etc/libnl/${f} ${DESTDIR}${EGDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
