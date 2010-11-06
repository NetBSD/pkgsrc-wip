# $NetBSD: Makefile,v 1.1.1.1 2010/11/06 10:53:44 grasmi Exp $
#

DISTNAME=	libnfo-1.0.0
CATEGORIES=	multimedia
MASTER_SITES=	http://libnfo.geexbox.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jrbleboss@gmail.com
HOMEPAGE=	http://libnfo.geexbox.org/
COMMENT=	Library used to parse and write NFO files
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake
USE_TOOLS+=	diff

PKG_DESTDIR_SUPPORT= user-destdir

CONFIGURE_ARGS+= --prefix=${PREFIX}

HAS_CONFIGURE=yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
