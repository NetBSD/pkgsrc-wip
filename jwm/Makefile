# $NetBSD: Makefile,v 1.1.1.3 2005/09/27 17:55:11 pippijn Exp $
#

DISTNAME=	jwm-0.24
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	http://www.joewing.net/programs/jwm/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pip88nl@gmail.com
HOMEPAGE=	http://joewing.net/programs/jwm
COMMENT=	Lightweight window manager with virtual desktops
SUBDIR+=	jwm

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	jwm<=0.23

USE_PKGINSTALL=	YES
GNU_CONFIGURE=          yes
CONFIGURE_ARGS+=        --prefix=${PREFIX} \
			--sysconfdir=${PKG_SYSCONFDIR}

CFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

PKG_SYSCONFSUBDIR=	jwm

EGDIR=		${PREFIX}/share/examples/jwm
CONF_FILES= 	${EGDIR}/example.jwmrc ${PKG_SYSCONFDIR}/system.jwmrc

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
