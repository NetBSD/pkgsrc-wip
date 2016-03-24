# $NetBSD: Makefile,v 1.7 2012/10/05 13:52:02 asau Exp $
#

GITHUB_PROJECT=		polipo
DISTNAME=		polipo-1.1.1
CATEGORIES=		www
MASTER_SITES=		${MASTER_SITE_GITHUB:=jech/}
GITHUB_TAG=		${DISTNAME}
MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.pps.univ-paris-diderot.fr/~jch/software/polipo/
COMMENT=		Small and fast caching web proxy

USE_TOOLS+=	makeinfo

INFO_FILES=	# PLIST

BUILD_DEFS+=	VARBASE

# POLIPO_USER?=		polipo
# POLIPO_GROUP?=		polipo
# PKG_USERS_VARS+=	POLIPO_USER
# PKG_GROUPS_VARS+=	POLIPO_GROUP

MAKE_DIRS=		${VARBASE}/cache/polipo	${VARBASE}/log/polipo
MAKE_DIRS+=		${VARBASE}/run/polipo
# MAKE_DIRS_PERMS+=	${VARBASE}/cache/polipo ${POLIPO_USER} ${POLIPO_GROUP} 0750
# MAKE_DIRS_PERMS+=	${VARBASE}/log/polipo ${POLIPO_USER} ${POLIPO_GROUP} 0755
# MAKE_DIRS_PERMS+=	${VARBASE}/run/polipo ${POLIPO_USER} ${POLIPO_GROUP} 0755

PKG_SYSCONFSUBDIR=	polipo
CONF_FILES=		${PREFIX}/share/polipo/config.sample ${PKG_SYSCONFDIR}/config

RCD_SCRIPTS=		polipo

SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-configure
SUBST_MESSAGE.fix-paths=	Fixing absolute paths.
SUBST_FILES.fix-paths=		Makefile *.sample polipo.man polipo.texi *.c
SUBST_SED.fix-paths=		-e 's,/usr/local,${PREFIX},g'
SUBST_SED.fix-paths+=		-e 's,/var/cache,${VARBASE}/cache,g'
SUBST_SED.fix-paths+=		-e 's,/etc/polipo,${PKG_SYSCONFDIR},g'
SUBST_SED.fix-paths+=		-e 's,/var/log/polipo,/var/log/polipo/polipo.log,g'

INSTALLATION_DIRS=	bin info ${PKGMANDIR}/man1 share/polipo/www

post-build:
	${CP} ${WRKSRC}/polipo.man ${WRKSRC}/polipo.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/polipo ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/polipo.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/*.sample ${DESTDIR}${PREFIX}/share/polipo
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/polipo
	${INSTALL_DATA} ${WRKSRC}/html/* ${DESTDIR}${PREFIX}/share/polipo/www
	${INSTALL_DATA} ${WRKSRC}/polipo.info ${DESTDIR}${PREFIX}/info

.include "../../mk/bsd.pkg.mk"
