# $NetBSD: Makefile,v 1.4 2009/07/22 09:53:11 thomasklausner Exp $
#

PKGNAME=	filezilla-3.2.3.1
DISTNAME=	FileZilla_3.2.3.1_src
CATEGORIES=	net x11
MASTER_SITES=	http://d10xg45o6p6dbl.cloudfront.net/projects/f/filezilla/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://filezilla-project.org/
COMMENT=	FTP, FTPS and SFTP client with intuitive GUI

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config msgfmt msgmerge
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

CONFIGURE_ARGS+=	--disable-autoupdatecheck

.include "options.mk"

.include "../../devel/libidn/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../security/gnutls/libgnutls-config.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
