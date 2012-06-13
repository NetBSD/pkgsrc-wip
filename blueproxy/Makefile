# $NetBSD: Makefile,v 1.2 2012/06/13 16:53:14 othyro Exp $
#

DISTNAME=		blueproxy-1.3
CATEGORIES=		net
MASTER_SITES=		http://anil.recoil.org/projects/

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://anil.recoil.org/projects/blueproxy.html
COMMENT=		RFCOMM <-> TCP proxy
#LICENSE=		# TODO

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../wip/bluez-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
