# $NetBSD: Makefile,v 1.16 2010/06/13 22:47:16 thomasklausner Exp $

# DISTNAME=		spectrum
# PKGNAME=		${DISTNAME}-${GIT_TAG}
DISTNAME=		spectrum-v0.1s0
# PKGREVISION=		2
PKGREVISION=		1
CATEGORIES=		chat

# Second paragraph - MAINTAINER/OWNER, HOMEPAGE and COMMENT, and LICEN[CS]E
MAINTAINER=		eric@cirr.com
HOMEPAGE=		http://spectrum.im/
COMMENT=		XMPP transport/gateway based on libpurple
LICENSE=		gnu-gpl-v3
MASTER_SITES=		ftp://ftp.cirr.com/pub/eric/

# if the package can be created without root privileges
PKG_DESTDIR_SUPPORT=	user-destdir

# PREFER.gettext=		pkgsrc
# DEPENDS+=		gettext-tools>=0.0:../../devel/gettext-tools

# GIT configuration
# GIT_REPOSITORIES=	spectrum
# GIT_REPO.spectrum=	git://github.com/schnoebe/spectrum.git
# GIT_TAG=		v0.1s0

# .include "../../wip/mk/git-package.mk"

USE_TOOLS+=		pkg-config msgfmt
USE_CMAKE=		yes
USE_LANGUAGES+=		c++ c

REPLACE_PYTHON+=	spectrumctl/spectrumctl.py
PY_PATCHPLIST=		yes

# always include bsd.prefs.mk before any .if or .ifdef statements
.include "../../mk/bsd.prefs.mk"
.include "../../wip/jabberd/transports.mk"

PKG_SYSCONFSUBDIR=	spectrum
EGDIR=			${PREFIX}/share/examples/spectrum
RCD_SCRIPTS=		spectrum

CONF_FILES+=		${EGDIR}/spectrum.cfg ${PKG_SYSCONFDIR}/spectrum.cfg

.include "options.mk"

SUBST_CLASSES+=		cfgpath users
SUBST_STAGE.cfgpath=	post-patch
SUBST_FILES.cfgpath=	CMakeLists.txt
SUBST_FILES.cfgpath+=	src/configfile.cpp
SUBST_FILES.cfgpath+=	tools/migrate-db/main.cpp
SUBST_FILES.cfgpath+=	spectrumctl/spectrumctl.py
SUBST_FILES.cfgpath+=	man/spectrumctl.8
SUBST_MESSAGE.cfgpath=	Correcting configuration directory
SUBST_SED.cfgpath=	-e 's,/etc/spectrum,${PKG_SYSCONFDIR},g'
SUBST_SED.cfgpath+=	-e 's,@ETC_SPECTRUM@,${PKG_SYSCONFDIR},g'

SUBST_STAGE.users=	post-patch
SUBST_FILES.users=	spectrumctl/spectrumctl.py
SUBST_FILES.users+=	man/spectrumctl.8
SUBST_MESSAGE.users=	Correcting spectrum user
SUBST_SED.users=	-e 's/@SPECTRUM@/${JABBER_USER}/g'

MESSAGE_SUBST+=  EGDIR=${EGDIR:Q}
MESSAGE_SUBST+=  PREFIX=${PREFIX:Q}
MESSAGE_SUBST+=  PKG_SYSCONFDIR=${PKG_SYSCONFDIR:Q}

FILES_SUBST+=  PREFIX=${PREFIX:Q}
FILES_SUBST+=  JABBER_USER=${JABBER_USER:Q}

INSTALLATION_DIRS=	bin ${PKG_SYSCONFDIR} ${EGDIR}
INSTALLATION_DIRS+=	share/${PKGNAME}/certificates
INSTALLATION_DIRS+=	share/${PKGNAME}/locales
INSTALLATION_DIRS+=	${EGDIR}

pre-install:
	${MKDIR} ${DESTDIR}${PKG_SYSCONFDIR}
post-install:
	${INSTALL_DATA} ${WRKSRC}/spectrum.cfg ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/schemas/mysql_schema.sql \
					${DESTDIR}${EGDIR}/spectrum-mysql.sql
	${INSTALL_DATA} ${WRKSRC}/schemas/sqlite_schema.sql \
					${DESTDIR}${EGDIR}/spectrum-sqlite3.sql


.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../wip/poco/buildlink3.mk"
.include "../../wip/gloox/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
