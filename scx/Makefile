#
# $NetBSD: Makefile,v 1.4 2005/02/16 22:24:26 airhead Exp $
#

DISTNAME=		scx-0.2
CATEGORIES=		wip devel x11
MASTER_SITES=		ftp://ftp.scsh.net/pub/scsh/packages/scx/

MAINTAINER=		airhead@users.sf.net
HOMEPAGE=		http://www.scsh.net/resources/graphics.html
COMMENT=		Scx - a GUI library for scsh and Scheme 48

USE_LIBTOOL=		yes
USE_X11=		yes
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

.include "../../mk/bsd.pkg.mk"
