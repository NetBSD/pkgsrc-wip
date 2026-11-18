# $NetBSD: Makefile,v $

DISTNAME=	icinga-php-thirdparty-0.12.1
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}
GITHUB_TAG=	v${PKGVERSION_NOREV}
MASTER_SITES=	${MASTER_SITE_GITHUB:=icinga/}
CATEGORIES=	net sysutils www

MAINTAINER=	ef@math.uni-bonn.de
HOMEPAGE=	https://github.com/Icinga/icinga-php-thirdparty
COMMENT=	Bundle for all 3rd party PHP libraries used by Icinga Web products
LICENSE=	mit AND apache-2.0 AND modified-bsd AND isc AND gnu-lgpl-v2.1 AND gnu-lgpl-v3

DEPENDS+=	dejavu-ttf-[0-9]*:../../fonts/dejavu-ttf
DEPENDS+=	${PHP_PKG_PREFIX}-curl-[0-9]*:../../www/php-curl
DEPENDS+=	${PHP_PKG_PREFIX}-soap-[0-9]*:../../net/php-soap
DEPENDS+=	${PHP_PKG_PREFIX}-sockets-[0-9]*:../../net/php-sockets

PHP_REQUIRE_MODULE=	json

PHP_VERSIONS_ACCEPTED=	82 83 84

USE_TOOLS+=	pax

USE_LANGUAGES=	# empty
NO_BUILD=	YES

# Can't set NO_CONFIGURE=YES since REPLACE_INTERPRETER needs a configure phase and phpversion.mk uses that
do-configure:

# Note that INCDIR ends in icinga-php, not icinga-php-thirdparty.
INCDIR=			${PREFIX}/${PHP_LIBDIR}/icinga-php
VENDORDIR=		${INCDIR}/vendor
DOCDIR=			${PREFIX}/share/doc/icinga-php-thirdparty
# The distribution's "vendor" subdirectory is installed into .../icinga-php/vendor, giving .../icinga-php/vendor/vendor/...
INSTALLATION_DIRS+=	${INCDIR} ${VENDORDIR} ${DOCDIR}

.include "../../mk/bsd.prefs.mk"

# The upstream distribution is not exactly packaging-friendly. It's kind of a blob, no Makefile etc.
# The packaging here mostly mimics what Debian does

FIND_RM_FILES=	CHANGELOG.md
FIND_RM_FILES+=	CHANGELOG_v\*.md
FIND_RM_FILES+=	CHANGES.md
FIND_RM_FILES+=	LICENSE LICENSE.md LICENSE.txt
FIND_RM_FILES+=	README
FIND_RM_FILES+=	README.md
FIND_RM_FILES+=	readme.md
FIND_RM_FILES+=	DEVELOPMENT_README.md
FIND_RM_FILES+=	README-GIT.md
FIND_RM_FILES+=	UPGRADING.md
FIND_RM_FILES+=	UPGRADING_v\*.md
FIND_RM_FILES+=	SECURITY.md
FIND_RM_FILES+=	CONTRIBUTING.md
FIND_RM_FILES+=	INSTALL.md
FIND_RM_FILES+=	PATCHES.txt
FIND_RM_FILES+=	AUTHORS.md
FIND_RM_FILES+=	API.md
FIND_RM_FILES+=	CODE_OF_CONDUCT.md

RM_FILES=	doctrine/collections/docs/en/derived-collections.rst
RM_FILES+=	doctrine/collections/docs/en/expression-builder.rst
RM_FILES+=	doctrine/collections/docs/en/expressions.rst
RM_FILES+=	doctrine/collections/docs/en/index.rst
RM_FILES+=	doctrine/collections/docs/en/lazy-collections.rst
RM_FILES+=	doctrine/collections/docs/en/sidebar.rst
RM_FILES+=	dompdf/dompdf/LICENSE.LGPL

RM_FILES+=	predis/predis/docker/unstable_cluster/Dockerfile
RM_FILES+=	predis/predis/docker/unstable_cluster/create_cluster.sh
RM_FILES+=	predis/predis/docker/unstable_cluster/docker-compose.yml
RM_FILES+=	predis/predis/docker/unstable_cluster/redis.conf
RM_FILES+=	psr/http-message/docs/PSR7-Interfaces.md
RM_FILES+=	psr/http-message/docs/PSR7-Usage.md
RM_FILES+=	shardj/zf1-future/library/Zend/Service/WindowsAzure/CommandLine/Scaffolders/DefaultScaffolder/resources/PhpOnAzure.Web/resources/WebPICmdLine/Microsoft.Web.Deployment.dll
RM_FILES+=	shardj/zf1-future/library/Zend/Service/WindowsAzure/CommandLine/Scaffolders/DefaultScaffolder/resources/PhpOnAzure.Web/resources/WebPICmdLine/Microsoft.Web.PlatformInstaller.UI.dll
RM_FILES+=	shardj/zf1-future/library/Zend/Service/WindowsAzure/CommandLine/Scaffolders/DefaultScaffolder/resources/PhpOnAzure.Web/resources/WebPICmdLine/Microsoft.Web.PlatformInstaller.dll
RM_FILES+=	shardj/zf1-future/library/Zend/Service/WindowsAzure/CommandLine/Scaffolders/DefaultScaffolder/resources/PhpOnAzure.Web/resources/WebPICmdLine/WebpiCmdLine.exe
RM_FILES+=	shardj/zf1-future/library/Zend/Service/WindowsAzure/CommandLine/Scaffolders/DefaultScaffolder/resources/PhpOnAzure.Web/resources/WebPICmdLine/license.rtf
RM_FILES+=	simshaun/recurr/test.ps1
RM_FILES+=	simshaun/recurr/test.sh

#NONEXEC_FILES=	ezyang/htmlpurifier/library/HTMLPurifier/DefinitionCache/Serializer/README
NONEXEC_DIRS=	shardj/zf1-future/library/Zend

# Install the files
do-install:
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/vendor/wikimedia/less.php/NOTICE.txt ${DESTDIR}${DOCDIR}
	${RM} ${WRKSRC}/vendor/wikimedia/less.php/NOTICE.txt
	${INSTALL_DATA} ${WRKSRC}/VERSION ${DESTDIR}${VENDORDIR}
	# vendor is put inside VENDORDIR, which is INCDIR/vendor, resulting in .../icinga-php/vendor/vendor/...
	cd ${WRKSRC} && ${PAX} -rw -pmp asset composer.json composer.lock vendor ${DESTDIR}${VENDORDIR}
	${FIND} ${DESTDIR}${VENDORDIR}/vendor -name ${FIND_RM_FILES:S/ / -or -name /gW} | ${XARGS} ${RM}
	cd ${DESTDIR}${VENDORDIR}/vendor && ${RM} ${RM_FILES}
#	cd ${DESTDIR}${VENDORDIR}/vendor && ${CHMOD} -x ${NONEXEC_FILES}
	${FIND} ${NONEXEC_DIRS:S.^.${DESTDIR}${VENDORDIR}/vendor/.} -type f | ${XARGS} ${CHMOD} -x

PLIST_SUBST+=	DOCDIR="${DOCDIR:S.${PREFIX}/..}"
PLIST_SUBST+=	INCDIR="${INCDIR:S.${PREFIX}/..}"
PLIST_SUBST+=	VENDORDIR="${VENDORDIR:S.${PREFIX}/..}"

.include "../../lang/php/compat.mk"
.include "../../mk/bsd.pkg.mk"
