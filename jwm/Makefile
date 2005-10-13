# $NetBSD: Makefile,v 1.2 2005/10/13 15:46:24 ghen Exp $
#

DISTNAME=	jwm-0.24
PKGREVISION=	1
CATEGORIES=	wm x11
MASTER_SITES=	http://www.joewing.net/programs/jwm/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pip88nl@gmail.com
HOMEPAGE=	http://joewing.net/programs/jwm
COMMENT=	Lightweight window manager with virtual desktops

USE_PKGINSTALL=		YES
GNU_CONFIGURE=          yes
CONFIGURE_ARGS+=        --sysconfdir=${PKG_SYSCONFDIR}

PKG_SYSCONFSUBDIR=	jwm

INSTALLATION_DIRS=	share/examples/jwm

EGDIR=		${PREFIX}/share/examples/jwm
CONF_FILES= 	${EGDIR}/system.jwmrc ${PKG_SYSCONFDIR}/system.jwmrc

SUBST_CLASSES+=		egdir
SUBST_STAGE.egdir=	post-patch
SUBST_FILES.egdir=	Makefile.in
SUBST_SED.egdir=	-e 's,@@EGDIR@@,${EGDIR},g'

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
