# $NetBSD: Makefile,v 1.7 2012/10/07 16:22:55 asau Exp $

DISTNAME=		scx-0.2
CATEGORIES=		devel x11
MASTER_SITES=		http://ftp.scsh.net/pub/scsh/packages/scx/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.scsh.net/resources/graphics.html
COMMENT=		Scx - a GUI library for scsh and Scheme 48


USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-scsh-includes=${PREFIX}/include

#
# XXX Nasty quick hack. so sue me for wanting to get orion to work asap ;)
#
BUILD_DEPENDS+=		scsh>=0.6:../../shells/scsh
BUILD_DEPENDS+=		scsh-install-lib>=1:../../wip/scsh-install-lib

do-install:
	cd ${WRKSRC}; \
	scsh-install-pkg --prefix=${PREFIX} \
			 --layout fhs \
			 --verbose

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
