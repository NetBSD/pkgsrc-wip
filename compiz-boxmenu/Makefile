# $NetBSD: Makefile,v 1.3 2015/04/13 23:22:01 othyro Exp $
#

DISTNAME=	compiz-boxmenu_-_1.1.9
PKGNAME=	${DISTNAME:S/_-_/-/1}
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=compizboxmenu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/compizboxmenu/
COMMENT=	Desktop menu for compiz, forked from compiz-deskmenu
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGBASE}
USE_LANGUAGES+=	c
USE_TOOLS+=	gmake m4 pkg-config

PYTHON_VERSIONS_ACCEPTED=	27

EGDIR=			share/examples/xdg/compiz/boxmenu
INSTALLATION_DIRS+=	${EGDIR}
CONF_FILES+=		${EGDIR}/menu.xml ${PKG_SYSCONFDIR}/share/examples/xdg/compiz/boxmenu/menu.xml
CONF_FILES+=		${EGDIR}/precache.ini ${PKG_SYSCONFDIR}/share/examples/xdg/compiz/boxmenu/precache.ini

post-install:
	${INSTALL_DATA} ${WRKSRC}/menu.xml ${DESTDIR}${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/precache.ini ${DESTDIR}${PREFIX}/${EGDIR}
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/xdg/compiz/boxmenu/menu.xml
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/xdg/compiz/boxmenu/precache.ini

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../devel/libwnck/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
