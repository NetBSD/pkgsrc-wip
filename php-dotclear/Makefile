# $NetBSD$

DISTNAME=	dotclear-2.16
PKGNAME=	${PHP_PKG_PREFIX}-${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	https://download.dotclear.org/latest/ \
		https://download.dotclear.org/attic/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dotclear.org/
COMMENT=	Open-source web publising software
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=${PHP_BASE_VERS}:../../converters/php-mbstring
DEPENDS+=	${PHP_PKG_PREFIX}-iconv>=${PHP_BASE_VERS}:../../converters/php-iconv

.include "options.mk"
.include "../../lang/php/phpversion.mk"

NO_BUILD=		yes
USE_TOOLS+=		pax
WRKSRC=			${WRKDIR}/dotclear
BUILD_DEFS+=		VARBASE WWW_USER WWW_GROUP

INSTALLATION_DIRS=	${DCDIR} ${DOCDIR} ${EGDIR}

PKG_SYSCONFSUBDIR?=	dotclear

PKG_USERS_VARS=		WWW_USER
PKG_GROUPS_VARS=	WWW_GROUP

DCDIR=			${PREFIX}/share/dotclear
DOCDIR=			${PREFIX}/share/doc/dotclear
EGDIR=			${PREFIX}/share/examples/dotclear

PAX_DIRS=		admin inc locales plugins themes
DOC_FILES=		CHANGELOG CONTRIBUTING.md CREDITS LICENSE README.md
CONF_FILES=		${EGDIR}/dotclear.conf \
			${PKG_SYSCONFDIR}/dotclear.conf
CONF_FILES+=		${EGDIR}/config.php.in \
			${PKG_SYSCONFDIR}/config.php.in
OWN_DIRS_PERMS+=	${VARBASE}/cache/dotclear \
			${WWW_USER} ${WWW_GROUP} 750
OWN_DIRS_PERMS+=	${VARBASE}/www/dotclear \
			${WWW_USER} ${WWW_GROUP} 750
OWN_DIRS_PERMS+=	${VARBASE}/www/dotclear/public \
			${WWW_USER} ${WWW_GROUP} 750

SUBST_CLASSES+=		files
SUBST_STAGE.files=	do-configure
SUBST_MESSAGE.files=	Fixing configuration files.
SUBST_FILES.files=	dotclear.conf inc/config.php.in
SUBST_FILES.files+=	inc/prepend.php inc/core/class.dc.core.php
SUBST_FILES.files+=	admin/install/index.php admin/install/wizard.php
SUBST_VARS.files=	DCDIR
SUBST_VARS.files+=	VARBASE
SUBST_VARS.files+=	PKG_SYSCONFDIR
SUBST_VARS.files+=	WWW_SYSCONFDIR
SUBST_SED.files+=	-e "s|@DC_ROOT@|${PREFIX}/share|g"
SUBST_SED.files+=	-e "s|@DC_CACHE@|${VARBASE}/cache/dotclear|g"
SUBST_SED.files+=	-e "s|@DC_WWW@|${VARBASE}/www/dotclear|g"
SUBST_SED.files+=	-e "s|@DC_DBDIR@|${VARBASE}/db/dotclear|g"

NON_EXEC_FILES=		admin/images/grid-off.png admin/images/grid-on.png \
			admin/images/list-off.png admin/images/list-on.png \
			plugins/breadcrumb/_admin.php plugins/breadcrumb/_define.php \
			plugins/breadcrumb/_public.php plugins/dcLegacyEditor/icon.png \
			themes/berlin/_define.php themes/berlin/locales/de/main.po \
			themes/berlin/locales/en/main.po themes/berlin/locales/es/main.po \
			themes/berlin/locales/fr/main.po themes/berlin/scripts/boxsizing.htc \
			themes/berlin/scss/libs/_scut.scss \
			themes/berlin/scss/libs/sass-mq-master/LICENSE.md \
			themes/berlin/scss/libs/sass-mq-master/README.md \
			themes/berlin/scss/libs/sass-mq-master/_mq.scss \
			themes/berlin/scss/libs/zen-grids/_background.scss \
			themes/berlin/scss/libs/zen-grids/_flow.scss \
			themes/berlin/scss/libs/zen-grids/_grids.scss

post-extract:
	${CP} ${FILESDIR}/${WWW_CONF_FILE} ${WRKSRC}/dotclear.conf
# XXX in 2.9.1, executable bit is set on non-executable file
.for f in ${NON_EXEC_FILES}
	${CHMOD} -x ${WRKSRC}/${f}
.endfor

do-install:
	${INSTALL_DATA} ${WRKSRC}/index.php ${DESTDIR}${DCDIR}
	${INSTALL_DATA} ${WRKSRC}/inc/config.php.in ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/dotclear.conf ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${FILESDIR}/init-*.sh ${DESTDIR}${EGDIR}
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor
.for d in ${PAX_DIRS}
	${INSTALL_DATA_DIR} ${DESTDIR}${DCDIR}/${d}
	cd ${WRKSRC}/${d} && \
		${FIND} . -type f \! -name "config.php.in" \! -name "*.orig" -print | \
		${PAX} -rw ${DESTDIR}${DCDIR}/${d}
.endfor
.for f in ${DOC_FILES}
.endfor

.include "../../mk/bsd.pkg.mk"
