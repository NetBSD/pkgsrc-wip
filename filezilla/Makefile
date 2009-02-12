# $NetBSD: Makefile,v 1.1.1.1 2009/02/12 14:17:03 tnn2 Exp $
#

PKGNAME=	filezilla-3.2.1
DISTNAME=	FileZilla_3.2.1_src
CATEGORIES=	net x11
MASTER_SITES=	http://d10xg45o6p6dbl.cloudfront.net/projects/f/filezilla/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://filezilla-project.org/
COMMENT=	FTP, FTPS and SFTP client with intuitive GUI

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_DIRS+=	xdg-1.4
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

.include "../../devel/libidn/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
# XXX dbus should be PKG_OPTION
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
