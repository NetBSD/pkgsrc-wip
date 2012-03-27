# $NetBSD: Makefile,v 1.1.1.1 2012/03/27 16:00:57 outpaddling Exp $
#

DISTNAME=	ufc-2.0.5
CATEGORIES=	math
MASTER_SITES=	http://launchpad.net/ufc/2.0.x/2.0.5/+download/

MAINTAINER=	jwbacon@tds.net
HOMEPAGE=	http://launchpad.net/ufc/2.0.x/2.0.5/+download/
COMMENT=	Unified framework for finite element assembly
LICENSE=	public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	cmake/ufc-1.pc.in

.include "../../mk/bsd.pkg.mk"
