# $NetBSD: Makefile,v 1.1.1.1 2010/09/17 11:12:36 fhajny Exp $

PKGNAME=		${PHP_PKG_PREFIX}-fpm-${PHP_BASE_VERS}
CATEGORIES=		www

HOMEPAGE=		http://php-fpm.org/
MAINTAINER=		filip@joyent.com
COMMENT=		FPM interface for ${PKG_PHP}
LICENSE=		2-clause-bsd

PHP_VERSIONS_ACCEPTED=	53

PKG_DESTDIR_SUPPORT=	user-destdir

EGDIR=			${PREFIX}/share/examples/php
CONF_FILES=		${EGDIR}/php-fpm.conf ${PKG_SYSCONFDIR}/php-fpm.conf
AUTO_MKDIRS=		yes

CONFIGURE_ARGS+=	--enable-fpm
CONFIGURE_ARGS+=	--with-libevent-dir=${BUILDLINK_PREFIX.libevent}
CONFIGURE_ARGS+=	--with-fpm-user=www
CONFIGURE_ARGS+=	--with-fpm-group=www

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/fpm/php-fpm ${DESTDIR}${PREFIX}/sbin/php-fpm
	${INSTALL_MAN} ${WRKSRC}/sapi/fpm/php-fpm.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/sapi/fpm/php-fpm.conf ${DESTDIR}${EGDIR}

.include "../../devel/libevent/buildlink3.mk"
.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/Makefile.php"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
