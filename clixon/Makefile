# $NetBSD$

DISTNAME=	clixon-7.1.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=clicon/}
GITHUB_PROJECT=	clixon
DISTFILES+=	${PKGNAME_NOREV}.tar.gz

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	https://www.clicon.org/
COMMENT=	YANG-based configuration manager
LICENSE=	apache-2.0 OR gnu-gpl-v2

USE_LANGUAGES=	c
GNU_CONFIGURE=	yes

USE_TOOLS+=	gmake bison autoconf

CLIXON_USER?=	clixon
CLIXON_GROUP?=	clixon

PKG_USERS=		${CLIXON_USER}:${CLIXON_GROUP}
PKG_GROUPS=		${CLIXON_GROUP}
PKG_USERS_VARS+=	CLIXON_USER
PKG_GROUPS_VARS+=	CLIXON_GROUP

# Material for options.mk...:
#CONFIGURE_ARGS+=	--with-restconf=fcgi
#.include "../../www/fcgi/buildlink3.mk"
CONFIGURE_ARGS+=	--with-restconf=native
#CONFIGURE_ARGS+=	--without-restconf

# Don't pick these from the PATH in the build scaffolding...
CONFIGURE_ENV+=	GREP=/usr/bin/grep
CONFIGURE_ENV+=	TAIL_BIN=/usr/bin/tail
CONFIGURE_ENV+=	WC_BIN=/usr/bin/wc
CONFIGURE_ENV+=	CAT_BIN=/bin/cat

EGDIR=		share/examples/${PKGBASE}
CONF_FILES+=	${EGDIR}/clixonrc ${PKG_SYSCONFDIR}/clixonrc

INSTALLATION_DIRS+=	${EGDIR}

pre-configure:
	cd ${WRKSRC} && autoconf

post-install:
	cd ${WRKSRC}/etc; \
		${INSTALL_DATA} clixonrc ${DESTDIR}/${PREFIX}/${EGDIR}

.include "../../wip/cligen/buildlink3.mk"
.include "../../www/nghttp2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
