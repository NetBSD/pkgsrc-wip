# $NetBSD: Makefile,v 1.2 2008/06/10 07:07:42 asau Exp $

DISTNAME=	pfe-0.33.69
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pfe/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://pfe.sourceforge.net/
COMMENT=	Portable FORTH Environment

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS+=	--with-regs
USE_TOOLS+=	perl pkg-config

.include "../../mk/bsd.pkg.mk"
