# $NetBSD: Makefile,v 1.3 2005/07/27 16:25:30 thomasklausner Exp $
#

DISTNAME=		gdam-0.942
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gdam/}

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://gdam.sourceforge.net/
COMMENT=		Digital DJ audio mixer

DEPENDS+=		mpg123>=0.0:../../audio/mpg123

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../devel/libglade/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
