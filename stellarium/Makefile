# $NetBSD: Makefile,v 1.1.1.1 2003/12/23 04:01:53 mpasternak Exp $
#

DISTNAME=		stellarium-0.5.1
CATEGORIES=		misc
MASTER_SITES=		http://stellarium.free.fr/download/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://stellarium.free.fr/
COMMENT=		Generate photorealistic skys with OpenGL

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	yes

.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
