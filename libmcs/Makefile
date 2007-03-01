# $NetBSD: Makefile,v 1.1.1.1 2007/03/01 03:14:51 netcap Exp $
#

DISTNAME=	mcs-0.4.1
CATEGORIES=	devel
MASTER_SITES=	http://sacredspiral.co.uk/~nenolod/mcs/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jfranz@bsdprojects.net
HOMEPAGE=	http://sacredspiral.co.uk/~nenolod/mcs/
COMMENT=	BSD licensed configuration database system

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	libmcs.pc.in

.include "../../mk/bsd.pkg.mk"
