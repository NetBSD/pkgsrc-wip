# $NetBSD

PKGNAME=	dict-server-2.0.0
CATEGORIES=	textproc

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/cheusov/dictd
COMMENT=	Dictionary Service Protocol server
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"

GIT_REPOSITORIES=	dictd
GIT_REPO.dictd=		https://github.com/cheusov/dictd.git

USE_TOOLS+=		yacc lex m4:run
TOOL_DEPENDS+=		mk-configure>=0.38.2:../../devel/mk-configure

DICTD_USER?=		dictd
.if ${OPSYS} == "Interix"
DICTD_GROUP?=		nogroup
.else
DICTD_GROUP?=		dictd
.endif

PKG_GROUPS=			${DICTD_GROUP}
PKG_USERS=			${DICTD_USER}:${DICTD_GROUP}
PKG_GECOS.${DICTD_USER}=	Dictionary\ protocol\ server\ user
#PKG_HOME.${DICT_USER}=		/nonexistent
#PKG_SHELL.${DICT_USER}=	${NOLOGIN}

RCD_SCRIPTS=		dictd

# for -L /var/log/dictd/<filename_or_pattern>
OWN_DIRS_PERMS=	${VARBASE}/log/dictd dictd dictd 0750

WRKSRC =		${WRKDIR}/dictd
EGDIR =			${PREFIX}/share/examples/dictd

CONF_FILES=		${EGDIR}/dictd.conf \
			${PKG_SYSCONFDIR}/dictd.conf

CONFIGURE_TARGET=	configure-dictd configure-dictzip configure-dictfmt
BUILD_TARGET=		all-dictd all-dictzip all-dictfmt
INSTALL_TARGET=		install-dictd install-dictzip install-dictfmt

post-install:
	${INSTALL_DATA} ${.CURDIR}/files/dictd.conf ${DESTDIR}${EGDIR}/

.include "../../devel/mk-configure/mk-c.mk"
.include "../../devel/libmaa/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../wip/mk/git-package.mk"
.include "../../mk/bsd.pkg.mk"
