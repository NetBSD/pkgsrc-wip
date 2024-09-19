# $NetBSD: Makefile,v 1.1 2013/12/13 13:14:08 hfath Exp $
#

DISTNAME=	awl-${LIBAWL_VERSION}
PKGNAME=	${PHP_PKG_PREFIX}-libawl-${LIBAWL_VERSION}
PKGREVISION=	${_GIT_PKGVERSION:S/.//g}
LIBAWL_VERSION=	0.53
CATEGORIES=	devel
MASTER_SITES=	http://debian.mcmillan.net.nz/packages/awl/

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://andrew.mcmillan.net.nz/projects/awl/
COMMENT=	PHP Andrew's Web Libraries
LICENSE=	gnu-gpl-v2

GIT_REPOSITORIES=	awl
GIT_REPO.awl=		git://repo.or.cz/awl.git
GIT_MODULE.awl=		awl

WRKSRC=		${WRKDIR}/awl

.include "../../lang/php/phpversion.mk"

DEPENDS+=	${PHP_PKG_PREFIX}-iconv-[0-9]*:../../converters/php-iconv
DEPENDS+=	${PHP_PKG_PREFIX}-gettext-[0-9]*:../../devel/php-gettext

INSTALLATION_DIRS=	${LIBAWLDIR} ${LIBAWLDIR}/inc ${LIBAWLDIR}/dba

do-install:
	cd ${WRKSRC}/dba;					\
	for f in *; do						\
		${INSTALL_DATA} "$$f"				\
		    ${DESTDIR}${PREFIX}/${LIBAWLDIR}/dba;	\
	done;

	cd ${WRKSRC}/inc;					\
	for f in *.php; do					\
		${INSTALL_DATA} "$$f"				\
		    ${DESTDIR}${PREFIX}/${LIBAWLDIR}/inc;	\
	done;

.include "../../wip/mk/git-package.mk"
.include "../../wip/php-libawl-git/Makefile.common"
.include "../../mk/bsd.pkg.mk"
