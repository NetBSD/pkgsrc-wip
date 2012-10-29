# $NetBSD: Makefile,v 1.7 2012/10/29 16:59:40 lexort Exp $
#

DISTNAME=	CRF++-0.54
PKGNAME=	${DISTNAME:tl:S/+/p/g}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=crfpp/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://crfpp.sourceforge.net/
COMMENT=	Yet Another CRF toolkit
LICENSE=	gnu-lgpl-v2.1 OR modified-bsd

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
