# $NetBSD: Makefile,v 1.2 2004/01/02 02:21:29 mpasternak Exp $
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
AUTOMAKE_REQD=		1.8
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

pre-configure:
	cd ${WRKSRC} && ./autogen.sh

.include "../../mk/automake.mk"
.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
