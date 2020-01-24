# $NetBSD: Makefile,v 1.7 2012/12/27 13:02:47 othyro Exp $
#

DISTNAME=	parcellite-1.0.2rc5
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=parcellite/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://parcellite.sourceforge.net/
COMMENT=	Parcellite is a lightweight GTK+ clipboard manager
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool msgfmt msgmerge perl pkg-config xgettext

EGDIR=			share/examples/xdg/autostart
INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart ${EGDIR}
CONF_FILES=		${EGDIR}/parcellite-startup.desktop ${PKG_SYSCONFDIR}/xdg/autostart/parcellite-startup.desktop

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/data/parcellite-startup.desktop ${DESTDIR}${PREFIX}/${EGDIR}
	${RM} ${DESTDIR}${PKG_SYSCONFDIR}/xdg/autostart/parcellite-startup.desktop

.include "../../mk/pthread.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
