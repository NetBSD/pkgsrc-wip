# $NetBSD: Makefile,v 1.1.1.1 2012/05/05 23:30:09 thomasklausner Exp $
#

DISTNAME=	nautilus-dropbox-1.4.0
CATEGORIES=	sysutils
MASTER_SITES=	https://www.dropbox.com/download?dl=packages/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dropbox.com/
COMMENT=	Dropbox nautilus integration
#LICENSE=	gnu-gpl-v3 AND http://creativecommons.org/licenses/by-nd/3.0/

DEPENDS+=	${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
BUILD_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

PKG_DESTDIR_SUPPORT=	user-destdir

FETCH_USING=		curl

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
REPLACE_PYTHON=		dropbox.in
REPLACE_PYTHON+=	rst2man.py

.include "../../lang/python/application.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/nautilus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
