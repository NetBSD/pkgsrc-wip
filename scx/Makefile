#
# $NetBSD: Makefile,v 1.3 2005/02/16 21:39:47 airhead Exp $
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

SCSH_VERSION?=		0.6

#
# XXX Nasty quick hack. so sue me for wanting to get orion to work asap ;)
#
BUILD_DEPENDS+=		scsh-${SCSH_VERSION}.[0-9]:../../shells/scsh
BUILD_DEPENDS+=		scsh-install-lib>=1:../../wip/scsh-install-lib

SCSH_LIBPATH=		${PREFIX}/share/scsh-${SCSH_VERSION}/modules

do-install:
	cd ${WRKSRC}; \
	env SCSH_LIB_DIRS=\"${SCSH_LIBPATH}\" \
	    scsh-install-pkg --prefix=${PREFIX} \
			     --layout fhs \
			     --verbose

.include "../../mk/bsd.pkg.mk"
