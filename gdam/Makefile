# $NetBSD: Makefile,v 1.2 2005/04/11 21:12:23 tvierling Exp $
#

DISTNAME=		gdam-0.942
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gdam/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://gdam.sourceforge.net/
COMMENT=		Digital DJ audio mixer

DEPENDS+=		mpg123>=0.0:../../audio/mpg123

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../devel/libglade/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
