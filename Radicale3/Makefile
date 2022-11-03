# $NetBSD$

DISTNAME=	Radicale-3.1.8
CATEGORIES=	net time www
MASTER_SITES=	${MASTER_SITE_PYPI:=R/Radicale/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://radicale.org/
COMMENT=	CalDAV (calendar) and CardDAV (contact) server
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-vobject-[0-9]*:../../textproc/py-vobject
DEPENDS+=	${PYPKGPREFIX}-defusedxml-[0-9]*:../../textproc/py-defusedxml
DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil

# for md5 htpasswd_encryption method
DEPENDS+=	${PYPKGPREFIX}-passlib-[0-9]*:../../security/py-passlib

DEPENDS+=	daemonize>=1.7.8:../../sysutils/daemonize

BUILD_DEFS+=			VARBASE

RADICALE_USER?=			radicale
RADICALE_GROUP?=		radicale
PKG_GROUPS=			${RADICALE_GROUP}
PKG_USERS=			${RADICALE_USER}:${RADICALE_GROUP}

PYTHON_VERSIONS_INCOMPATIBLE=	27
PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

PKG_SYSCONFSUBDIR=	radicale

RCD_SCRIPTS=		radicale

EGDIR=			share/examples/radicale
DOCDIR=			share/doc/radicale
INSTALLATION_DIRS=	${EGDIR} ${DOCDIR}

RADICALE_LOGDIR=	${VARBASE}/log/radicale
OWN_DIRS_PERMS+=	${RADICALE_LOGDIR} ${RADICALE_USER} \
				${RADICALE_GROUP} 0750
RADICALE_DATADIR=	${VARBASE}/radicale
OWN_DIRS_PERMS+=	${RADICALE_DATADIR} ${RADICALE_USER} \
				${RADICALE_GROUP} 0750

CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/config
CONF_FILES+=		${EGDIR}/rights ${PKG_SYSCONFDIR}/rights

FILES_SUBST+=		RADICALE_USER=${RADICALE_USER}
FILES_SUBST+=		RADICALE_GROUP=${RADICALE_GROUP}
FILES_SUBST+=		RADICALE_LOGDIR=${RADICALE_LOGDIR}
FILES_SUBST+=		PYTHONBIN=${PYTHONBIN}

SUBST_CLASSES+=		config
SUBST_SED.config+=	-e 's,/etc/radicale,${PKG_SYSCONFDIR},g'
SUBST_SED.config+=	-e 's,/var/lib/,${VARBASE}/,g'
SUBST_FILES.config+=	radicale/config.py config rights
SUBST_FILES.config+=	DOCUMENTATION.md
SUBST_STAGE.config=	pre-configure
SUBST_MESSAGE.config=	Fixing path to configuration file

SUBST_CLASSES+=		server
SUBST_SED.server+=	-e 's,\#filesystem_folder,filesystem_folder,'
SUBST_FILES.server+=	config
SUBST_STAGE.server=	pre-configure
SUBST_MESSAGE.server=	Adapt default collection location

post-install:
.for docf in config rights radicale.wsgi
	${INSTALL_DATA} ${WRKSRC}/${docf} ${DESTDIR}${PREFIX}/${EGDIR}/${docf}
.endfor
.for docf in CHANGELOG COPYING DOCUMENTATION README
	${INSTALL_DATA} ${WRKSRC}/${docf}.md \
		${DESTDIR}${PREFIX}/${DOCDIR}/${docf}.md
.endfor

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
