# $NetBSD: Makefile,v 1.10 2006/02/12 20:33:04 pippijn Exp $
#

DISTNAME=		jwm-1.4
CATEGORIES=		wm x11
MASTER_SITES=		http://www.joewing.net/programs/jwm/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pip88nl@gmail.com
HOMEPAGE=		http://joewing.net/programs/jwm
COMMENT=		Lightweight window manager with virtual desktops

GNU_CONFIGURE=		yes
USE_PKGINSTALL=		yes

.include "../../mk/bsd.prefs.mk"

.if exists(${X11BASE}/include/X11/extensions/Xinerama.h)
CONFIGURE_ARGS+=	--enable-xinerama
.endif

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

SUBST_CLASSES+=		egdir
SUBST_STAGE.egdir=	pre-configure
SUBST_FILES.egdir=	Makefile.in
SUBST_SED.egdir=	-e 's,@@EGDIR@@,${EGDIR},g'

PKG_SYSCONFSUBDIR=	jwm
EGDIR=			${PREFIX}/share/examples/jwm
CONF_FILES= 		${EGDIR}/system.jwmrc ${PKG_SYSCONFDIR}/system.jwmrc

.include "options.mk"

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
