# $NetBSD: Makefile,v 1.1 2013/08/22 11:13:22 obache Exp $

DISTNAME=	sa-1.2.6
PKGNAME=	ossp-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ossp.org/pkg/lib/sa/

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://www.ossp.org/pkg/lib/sa/
COMMENT=	OSSP sa - Socket Abstraction

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE+=	sa.pc.in

CONFIGURE_ARGS+=	--with-ex=${BUILDLINK_PREFIX.ossp-ex}

TEST_TARGET=		check

.include "../../wip/ossp-ex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
