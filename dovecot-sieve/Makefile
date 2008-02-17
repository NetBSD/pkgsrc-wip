# $NetBSD: Makefile,v 1.4 2008/02/17 19:37:41 ghen Exp $

DISTNAME=		dovecot-sieve-1.1.4
CATEGORIES=		mail
MASTER_SITES=		http://www.dovecot.org/releases/sieve/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://wiki.dovecot.org/LDA/Sieve
COMMENT=		Sieve plugin for Dovecot

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		pkg-config

CONFIGURE_ARGS+=	--with-dovecot=${PREFIX}/lib/dovecot

.include "../../wip/dovecot/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
