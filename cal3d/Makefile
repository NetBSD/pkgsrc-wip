# $NetBSD: Makefile,v 1.1.1.1 2003/11/05 03:48:09 mpasternak Exp $
#

DISTNAME=		cal3d-0.9
CATEGORIES=		graphics
MASTER_SITES=		http://cesnet.dl.sourceforge.net/sourceforge/cal3d/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://cesnet.dl.sourceforge.net/sourceforge/cal3d/
COMMENT=	        Skeletal based 3d character animation library in C++

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../mk/automake.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
