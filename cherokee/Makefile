# $NetBSD: Makefile,v 1.21 2010/01/17 12:03:23 thomasklausner Exp $
#

DISTNAME=	cherokee-0.99.28
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.cherokee-project.com/download/0.99/0.99.28/

MAINTAINER=	oivulf@gmail.com
HOMEPAGE=	http://www.cherokee-project.com/
COMMENT=	Flexible and fast web server

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_TOOLS+=		bison flex gmake

PKG_USERS= crazyhorse:www
CONFIGURE_ARGS+=  --with-wwwuser=crazyhorse
CONFIGURE_ARGS+=  --with-wwwgroup=www
CONFIGURE_ARGS+=	--with-wwwroot=${PREFIX}/share/cherokee

PKGCONFIG_OVERRIDE=	cherokee.pc.in

INSTALL_MAKE_FLAGS+=	sysconfdir=${EGDIR:Q}
OWN_DIRS=		${PKG_SYSCONFDIR}/cherokee
OWN_DIRS+=		${PKG_SYSCONFDIR}/cherokee/mods-enabled
OWN_DIRS+=		${PKG_SYSCONFDIR}/cherokee/sites-enabled
EGDIR=			${PREFIX}/share/examples/cherokee
MESSAGE_SUBST+=		EGDIR=${EGDIR:Q}

CONF_FILES+= ${PREFIX}/share/examples/cherokee/cherokee/cherokee.conf ${PKG_SYSCONFDIR}/cherokee.conf

RCD_SCRIPTS+=		cherokee


CONFIGURE_ARGS+=	--enable-ipv6
CONFIGURE_ARGS+=	--with-libssl
.include "../../security/openssl/buildlink3.mk"

pre-install:
	${INSTALL_DATA_DIR} ${EGDIR}/pam.d

.include "../../mk/bsd.pkg.mk"
