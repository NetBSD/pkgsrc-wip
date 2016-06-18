# $NetBSD: Makefile,v 1.1 2014/08/08 11:56:44 chybz Exp $

DISTNAME=	nanomsg-1.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=nanomsg/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://nanomsg.org/
COMMENT=	Scalability protocols library
LICENSE=	x11

USE_CMAKE=	yes

PKGCONFIG_OVERRIDE+=	libnanomsg.pc.in

.include "../../mk/bsd.pkg.mk"
