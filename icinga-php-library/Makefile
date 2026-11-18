# $NetBSD: Makefile,v $

DISTNAME=	icinga-php-library-0.14.2
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=icinga/}
CATEGORIES=	net sysutils www

MAINTAINER=	ef@math.uni-bonn.de
HOMEPAGE=	https://github.com/Icinga/icinga-php-library
COMMENT=	Bundle for all Icinga PHP libraries
LICENSE=	mit

DEPENDS+=	${PHP_PKG_PREFIX}-intl-[0-9]*:../../textproc/php-intl
DEPENDS+=	${PHP_PKG_PREFIX}-pdo-[0-9]*:../../databases/php-pdo

PHP_REQUIRE_MODULE=	json

PHP_VERSIONS_ACCEPTED=	82 83 84

USE_TOOLS+=	pax

USE_LANGUAGES=	# empty
NO_BUILD=	YES

# Can't set NO_CONFIGURE=YES since REPLACE_INTERPRETER needs a configure phase and phpversion.mk uses that
do-configure:

# Note that INCDIR ends in icinga-php, not icinga-php-library.
INCDIR=			${PREFIX}/${PHP_LIBDIR}/icinga-php
IPLDIR=			${INCDIR}/ipl
DOCDIR=			${PREFIX}/share/doc/icinga-php-library
INSTALLATION_DIRS+=	${INCDIR} ${IPLDIR} ${DOCDIR}

.include "../../mk/bsd.prefs.mk"

# The upstream distribution is not exactly packaging-friendly. It's kind of a blob, no Makefile etc.
# The packaging here mostly mimics what Debian does

# Avoid possible problems with file names containing spaces
post-extract:
	${MV} ${WRKSRC}/asset/static/font/icinga-icons/"Read Me.txt" ${WRKSRC}/asset/static/font/icinga-icons/Read_Me.txt

FIND_RM_FILES=	LICENSE

RM_FILES=	asset/static/font/icinga-icons/Read_Me.txt

# Install the files
do-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${DESTDIR}${IPLDIR}
	cd ${WRKSRC} && ${PAX} -rw -pmp asset composer.json composer.lock vendor ${DESTDIR}${IPLDIR}
	${FIND} ${DESTDIR}${IPLDIR}/vendor -name ${FIND_RM_FILES:S/ / -or -name /gW} | ${XARGS} ${RM}
	cd ${DESTDIR}${IPLDIR} && ${RM} ${RM_FILES}

PLIST_SUBST+=	DOCDIR="${DOCDIR:S.${PREFIX}/..}"
PLIST_SUBST+=	INCDIR="${INCDIR:S.${PREFIX}/..}"
PLIST_SUBST+=	IPLDIR="${IPLDIR:S.${PREFIX}/..}"

.include "../../lang/php/compat.mk"
.include "../../mk/bsd.pkg.mk"
