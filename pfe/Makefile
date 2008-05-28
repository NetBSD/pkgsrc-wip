# $NetBSD: Makefile,v 1.1.1.1 2008/05/28 12:02:45 asau Exp $

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
USE_TOOLS+=	perl

.include "../../mk/bsd.pkg.mk"
