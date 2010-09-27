# $NetBSD: Makefile,v 1.12 2010/09/27 15:29:51 ggergely Exp $
#

DISTNAME=	grisbi-0.5.9
PKGREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=grisbi/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://grisbi.sourceforge.net/
COMMENT=	Personal Finance Manager under Gnome/GTK

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config intltool gmake


INSTALLATION_DIRS=	${PKGMANDIR}/man1 ${PREFIX}/share/applications/

PKG_OPTIONS_VAR=                PKG_OPTIONS.gribsi
PKG_SUPPORTED_OPTIONS=          libofx
PKG_SUGGESTED_OPTIONS=          libofx

.include "../../mk/bsd.options.mk"

.if !empty (PKG_OPTIONS:Mlibofx)
.include "../../finance/libofx/buildlink3.mk"
CONFIGURE_ARGS+=	--with-libofx
.else
CONFIGURE_ARGS+=	--without-libofx
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/grisbi.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/src/grisbi.desktop \
			${DESTDIR}${PREFIX}/share/applications/


.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
