# $NetBSD: Makefile,v 1.3 2014/08/11 12:02:46 thomasklausner Exp $

DISTNAME=	libnfo-1.0.0
CATEGORIES=	multimedia
MASTER_SITES=	http://libnfo.geexbox.org/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jrbleboss@gmail.com
HOMEPAGE=	http://libnfo.geexbox.org/
COMMENT=	Library used to parse and write NFO files
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--prefix=${PREFIX}

HAS_CONFIGURE=	yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
