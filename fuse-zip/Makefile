# $NetBSD: Makefile,v 1.2 2015/05/04 21:14:52 thomasklausner Exp $

DISTNAME=	fuse-zip-0.4.0
PKGREVISION=	1
CATEGORIES=	filesystems
MASTER_SITES=	https://fuse-zip.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://code.google.com/p/fuse-zip/
COMMENT=	FUSE file system to navigate, extract, create, and modify ZIP archives
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c++
USE_TOOLS+=	gmake pkg-config

MAKE_FLAGS+=	INSTALLPREFIX=${DESTDIR}${PREFIX}

SUBST_CLASSES+=		man
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"
SUBST_FILES.man+=	Makefile
SUBST_STAGE.man=	pre-build
SUBST_MESSAGE.man=	Fixing man page installation path.

.include "../../archivers/libzip/buildlink3.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
