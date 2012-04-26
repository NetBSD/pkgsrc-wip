# $NetBSD: Makefile,v 1.2 2012/04/26 19:31:30 outpaddling Exp $
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
USE_LANGUAGES=	c c++ python
USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	cmake/ufc-1.pc.in

FETCH_USING=	curl

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
