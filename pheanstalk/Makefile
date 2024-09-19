# $NetBSD: Makefile,v 1.1 2014/05/01 15:25:56 othyro Exp $
#

DISTNAME=	v2.1.0
PKGNAME=	pheanstalk${DISTNAME:S/v/-/1}
CATEGORIES=	net
MASTER_SITES=	https://github.com/pda/pheanstalk/archive/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pda/pheanstalk
COMMENT=	PHP client for beanstalkd queue
LICENSE=	mit

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/doc/${PKGBASE} share/${PKGBASE}/scripts
INSTALLATION_DIRS+=	share/${PKGBASE}/classes/Pheanstalk/Command
INSTALLATION_DIRS+=	share/${PKGBASE}/classes/Pheanstalk/Exception
INSTALLATION_DIRS+=	share/${PKGBASE}/classes/Pheanstalk/Response
INSTALLATION_DIRS+=	share/${PKGBASE}/classes/Pheanstalk/Socket

SUBST_CLASSES+=		php
SUBST_FILES.php=	scripts/build_phar.php
SUBST_MESSAGE.php=	Fixing path to PHP interpreter.
SUBST_SED.php=		-e 's|/usr/bin/env php|${PREFIX}/bin/php|1'
SUBST_STAGE.php=	post-patch

.include "options.mk"

do-install:
	cd ${WRKSRC}; \
	${INSTALL_DATA} README.md ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}; \
	${INSTALL_DATA} composer.json ${DESTDIR}${PREFIX}/share/${PKGBASE}; \
	${INSTALL_DATA} pheanstalk_init.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}; \
	${INSTALL_DATA} classes/Pheanstalk/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/classes/Pheanstalk; \
	${INSTALL_DATA} classes/Pheanstalk/Command/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/classes/Pheanstalk/Command; \
	${INSTALL_DATA} classes/Pheanstalk/Exception/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/classes/Pheanstalk/Exception; \
	${INSTALL_DATA} classes/Pheanstalk/Response/ArrayResponse.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/classes/Pheanstalk/Response; \
	${INSTALL_DATA} classes/Pheanstalk/Socket/*.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/classes/Pheanstalk/Socket; \
	${INSTALL_DATA} scripts/build_phar.php \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/scripts

.include "../../lang/php/phpversion.mk"
.include "../../mk/bsd.pkg.mk"
