# $NetBSD: Makefile,v 1.2 2014/09/16 18:48:02 christtrekker Exp $

DISTNAME=	unar1.8.1_src
PKGNAME=	unarchiver-1.8.1
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
