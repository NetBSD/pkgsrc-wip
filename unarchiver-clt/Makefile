# $NetBSD: Makefile,v 1.1 2013/07/11 19:33:17 christtrekker Exp $

DISTNAME=	unar1.7_src
PKGNAME=	unar-1.7
CATEGORIES=	archivers
MASTER_SITES=	http://theunarchiver.googlecode.com/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	christtrekker@users.sourceforge.net
HOMEPAGE=	http://unarchiver.c3.cx/commandline
COMMENT=	Command-line tools for The Unarchiver
LICENSE=	gnu-lgpl-v2.1

WRKSRC=		${WRKDIR}/The*Unarchiver/XADMaster
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

NO_CONFIGURE=	yes
MAKE_FILE=	Makefile.linux

.include "../../devel/gnustep-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
