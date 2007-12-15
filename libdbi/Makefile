# $NetBSD: Makefile,v 1.1 2007/12/15 21:59:43 cheusov Exp $
#

DISTNAME=	libdbi-0.8.2
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libdbi/}

MAINTAINER=	cheusov@tut.by
HOMEPAGE=	http://libdbi.sourceforge.net/
COMMENT=	Database Independent Abstraction Layer for C

USE_LANGUAGES=		c

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-dependency-tracking
CONFIGURE_ARGS+=	--disable-docs

AUTO_MKDIRS=		yes

.include "../../mk/bsd.pkg.mk"
