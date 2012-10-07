# $NetBSD: Makefile,v 1.12 2012/10/07 20:11:09 asau Exp $

.include "../../wip/xfce48/Makefile.common"

DISTNAME=	exo-0.6.2
PKGNAME=	xfce4-exo-0.6.2
CATEGORIES=	x11
COMMENT=	Xfce extension library

XFCE4_PROJECT=  exo
XFCE4_BRANCH=   0.6

DEPENDS+=	p5-URI>=0:../../www/p5-URI

PKGCONFIG_OVERRIDE+=	exo/exo-1.pc.in

CONFIGURE_ARGS+=	--disable-python

PKG_SYSCONFSUBDIR=	xdg/xfce4
EGDIR=			${XFCE4_EGBASE}

MAKE_DIRS+=	${SYSCONFDIR}
MAKE_DIRS+=	${EGDIR} ${PREFIX}/share/xfce4 ${PREFIX}/share/xfce4/doc
.for f in C es fr id ja pt_BR tr
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/${f}
MAKE_DIRS+=	${PREFIX}/share/xfce4/doc/${f}/images
.endfor

CONF_FILES=		${EGDIR}/helpers.rc ${PKG_SYSCONFDIR}/helpers.rc
OWN_DIRS+=		${EGDIR}

SUBST_CLASSES+=		perl
SUBST_STAGE.perl=	pre-build
SUBST_FILES.perl+=	exo-helper/helpers/exo-compose-mail-1
SUBST_SED.perl+=	-e 's,/usr/bin/env.*perl,${PREFIX}/bin/perl,'
SUBST_MESSAGE.perl=	Fixing path to perl.

#BUILDLINK_API_DEPENDS.libnotify+=	libnotify>=0.4.0

#.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
#.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../wip/libxfce4util/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
