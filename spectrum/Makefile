# $NetBSD: Makefile,v 1.6 2010/01/20 14:04:59 thomasklausner Exp $

DISTNAME=		spectrum
PKGNAME=		${DISTNAME}-0.1
PKGREVISION=		2
CATEGORIES=		chat

# Second paragraph - MAINTAINER/OWNER, HOMEPAGE and COMMENT, and LICEN[CS]E
MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://spectrum.im/
COMMENT=		XMPP transport/gateway based on libpurple
LICENSE=		gnu-gpl-v3

# if the package can be created without root privileges
PKG_DESTDIR_SUPPORT=	user-destdir

# PREFER.gettext=		pkgsrc
# DEPENDS+=		gettext-tools>=0.0:../../devel/gettext-tools

# GIT configuration
GIT_REPOSITORIES=	spectrum
GIT_REPO.spectrum=	git://github.com/schnoebe/spectrum.git

.include "../../wip/mk/git-package.mk"

USE_TOOLS+=		pkg-config msgfmt
USE_CMAKE=		yes
USE_LANGUAGES+=		c++ c

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR=	jabberd
EGDIR=			${PREFIX}/share/examples/jabberd

CONF_FILES+=		${EGDIR}/spectrum.cfg ${PKG_SYSCONFDIR}/spectrum.cfg

.include "options.mk"

SUBST_CLASSES+=		cfgpath
SUBST_STAGE.cfgpath=	post-patch
SUBST_FILES.cfgpath=	CMakeLists.txt
SUBST_FILES.cfgpath+=	src/configfile.cpp
SUBST_FILES.cfgpath+=	tools/migrate-db/main.cpp
SUBST_FILES.cfgpath+=	tools/spectrumctl/spectrumctl
SUBST_MESSAGE.cfgpath=	Correcting configuration directory
SUBST_SED.cfgpath=	-e 's,/etc/spectrum,${PKG_SYSCONFDIR},g'

INSTALLATION_DIRS=	bin ${PKG_SYSCONFDIR}
INSTALLATION_DIRS+=	share/${PKGNAME}/certificates
INSTALLATION_DIRS+=	share/${PKGNAME}/locales
INSTALLATION_DIRS+=	share/examples/jabberd

post-install:
	${INSTALL_DATA} ${WRKSRC}/spectrum.cfg ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/schemas/mysql_schema.sql \
						${EGDIR}/spectrum-mysql.sql
	${INSTALL_DATA} ${WRKSRC}/schemas/sqlite_schema.sql \
						${EGDIR}/spectrum-sqlite3.sql


.include "../../wip/poco/buildlink3.mk"
.include "../../wip/gloox/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
