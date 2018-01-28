# $NetBSD: Makefile,v 1.6 2012/10/07 20:11:07 asau Exp $

DISTNAME=		workrave-1.8.5
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=workrave/}

MAINTAINER=		bsd@cs.ubc.ca
HOMEPAGE=		http://www.workrave.org/
COMMENT=		Wrist break reminder program for prevention of RSI


USE_LIBTOOL=		YES
USE_TOOLS+=		gmake pkg-config intltool
USE_LANGUAGES+=		c c++
USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--docdir="${PREFIX}/share/doc/${PKGBASE}"

# Under NetBSD, /usr/include/wchar.h requires either _ISOC99_SOURCE or
# _NETBSD_SOURCE to be defined to include definitions for vfwscanf, vswscanf,
# vwscanf, and wcstof (required by backend/src/Break.cc), since
# __STDC_VERSION__ doesn't appear to be defined by c++
CXXFLAGS+=		-D_ISOC99_SOURCE

INSTALL_MAKE_FLAGS+=	utilsdir=${EGDIR}/sound/events
EGDIR=			${PREFIX}/share/examples/${PKGBASE}
CONF_FILES+=		${EGDIR}/sound/events/workrave.soundlist \
			${PKG_SYSCONFDIR}/sound/events/workrave.soundlist

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
