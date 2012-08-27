# $NetBSD: Makefile,v 1.2 2012/08/27 14:55:29 fhajny Exp $
#

DISTNAME=	stud-0
CATEGORIES=	net

MAINTAINER=	filip@joyent.com
HOMEPAGE=	http://github.com/bumptech/stud
COMMENT=	Scalable TLS Unwrapping Daemon
LICENSE=	2-clause-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GIT_REPOSITORIES=	stud
GIT_REPO.stud=		git://github.com/bumptech/stud.git

USE_TOOLS+=		gmake

BUILD_DEFS+=		STUD_USER STUD_GROUP

STUD_USER?=		stud
STUD_GROUP?=		stud

PKG_GROUPS?=		${STUD_GROUP}
PKG_USERS?=		${STUD_USER}:${STUD_GROUP}
PKG_GECOS.${STUD_USER}=	stud daemon user

WRKSRC=			${WRKDIR}/${PKGBASE}
INSTALLATION_DIRS+=	bin share/examples/stud

CONF_FILES+=		share/examples/stud/stud.conf ${PKG_SYSCONFDIR}/stud.conf

post-install:
	cd ${WRKSRC} && ./stud --daemon --default-config | ${SED} \
	  -e '/user/s/".*"/"${STUD_USER}"/' \
	  -e '/group/s/".*"/"${STUD_GROUP}"/' \
	  > ${DESTDIR}${PREFIX}/share/examples/stud/stud.conf

.include "../../wip/mk/git-package.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
