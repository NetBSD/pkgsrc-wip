# $NetBSD: Makefile,v 1.5 2005/11/06 10:18:47 leonardschmidt Exp $
#

DISTNAME=		jwm-0.24
PKGREVISION=		1
CATEGORIES=		wm x11
MASTER_SITES=		http://www.joewing.net/programs/jwm/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pip88nl@gmail.com
HOMEPAGE=		http://joewing.net/programs/jwm
COMMENT=		Lightweight window manager with virtual desktops

GNU_CONFIGURE=          yes
USE_PKGINSTALL=		yes

CONFIGURE_ARGS+=        --sysconfdir=${PKG_SYSCONFDIR}

SUBST_CLASSES+=		egdir
SUBST_STAGE.egdir=	pre-configure
SUBST_FILES.egdir=	Makefile.in
SUBST_SED.egdir=	-e 's,@@EGDIR@@,${EGDIR},g'

PKG_SYSCONFSUBDIR=	jwm
EGDIR=			${PREFIX}/share/examples/jwm
CONF_FILES= 		${EGDIR}/system.jwmrc ${PKG_SYSCONFDIR}/system.jwmrc

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
