# $NetBSD$

VERSION=	1.8.4
PKGNAME=	${PHP_PKG_PREFIX}-composer-${VERSION}
DISTNAME=	composer
CATEGORIES=	devel
MASTER_SITES=	https://getcomposer.org/download/${VERSION}/
DIST_SUBDIR=	php-composer/${VERSION}
EXTRACT_SUFX=	.phar

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://getcomposer.org/
COMMENT=	Dependency Manager for PHP
LICENSE=	modified-bsd

NO_CONFIGURE=	yes
NO_BUILD=	yes
AUTO_MKDIRS=	yes

do-extract:
	${MKDIR} -m 0755 ${WRKSRC}
	${INSTALL} -m 0644 ${FILESDIR}/composer ${WRKSRC}/composer

do-install:
	${INSTALL} -m 0755 ${WRKSRC}/composer ${DESTDIR}${PREFIX}/bin/composer
	${INSTALL} -m 0644 ${DISTDIR}/${DIST_SUBDIR}/composer.phar \
		${DESTDIR}${PREFIX}/share/php/composer.phar

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		post-extract
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		composer
SUBST_VARS.fix-paths=		PREFIX

.include "../../lang/php/phpversion.mk"
.include "../../lang/python/application.mk"

.include "../../mk/bsd.pkg.mk"
