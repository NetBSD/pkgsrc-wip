# $NetBSD: Makefile,v 1.1.1.1 2004/03/06 16:13:51 mpasternak Exp $
#

DISTNAME=		gdam-0.942
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gdam/}

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://gdam.sourceforge.net/
COMMENT=		Digital DJ audio mixer

DEPENDS+=		mpg123>=0.0:../../audio/mpg123

USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

.include "../../devel/libglade/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
