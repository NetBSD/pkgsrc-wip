# $NetBSD: Makefile,v 1.1 2013/08/22 11:14:08 obache Exp $

DISTNAME=	val-0.9.4
PKGNAME=	ossp-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ossp.org/pkg/lib/val/

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://www.ossp.org/pkg/lib/val/
COMMENT=	OSSP val - String Manipulations

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-ex=${BUILDLINK_PREFIX.ossp-ex}

TEST_TARGET=		check

.include "../../wip/ossp-ex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
