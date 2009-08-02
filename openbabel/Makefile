# $NetBSD: Makefile,v 1.1 2009/08/02 17:57:30 fulviociriaco Exp $
#

DISTNAME=	openbabel-2.2.2
CATEGORIES=	wip biology
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openbabel/}

MAINTAINER=	oivulf@gmail.com
HOMEPAGE=	http://openbabel.sourceforge.net/
COMMENT=	a smart translator among chemical formats

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	openbabel-2.0.pc.in

.include "../../mk/bsd.pkg.mk"
