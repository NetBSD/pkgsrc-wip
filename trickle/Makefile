# $NetBSD: Makefile,v 1.1.1.1 2003/06/04 16:41:27 xtraeme Exp $
#

DISTNAME=	trickle-1.06
CATEGORIES=	net
MASTER_SITES=	http://monkey.org/~marius/trickle/

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://monkey.org/~marius/trickle/
COMMENT=	Portable lightweight userspace bandwidth shaper

USE_BUILDLINK2=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../devel/libevent/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
