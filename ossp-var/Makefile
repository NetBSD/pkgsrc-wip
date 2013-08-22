# $NetBSD: Makefile,v 1.1 2013/08/22 11:14:58 obache Exp $

DISTNAME=	var-1.1.3
PKGNAME=	ossp-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.ossp.org/pkg/lib/var/

MAINTAINER=	obache@users.sourceforge.net
HOMEPAGE=	http://www.ossp.org/pkg/lib/var/
COMMENT=	OSSP var - String Manipulations

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--with-ex=${BUILDLINK_PREFIX.ossp-ex}

TEST_TARGET=		check

.include "../../wip/ossp-ex/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
