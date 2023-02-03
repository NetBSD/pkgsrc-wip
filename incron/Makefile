# $NetBSD$

DISTNAME=	incron-0.5.10
CATEGORIES=	sysutils
MASTER_SITES=	http://inotify.aiken.cz/download/incron/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://inotify.aiken.cz/?section=incron&page=doc&lang=en
COMMENT=	Inotify cron system
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Linux"
LDFLAGS+=	-linotify
.endif
#CXXFLAGS+=	-g

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Substituting hard-coded system paths
SUBST_STAGE.paths=	pre-build
SUBST_FILES.paths=	\
	appinst.h \
	incron.conf.5 \
	incron.conf.example \
	incron.h \
	incroncfg.cpp
SUBST_VARS.paths=	PKG_SYSCONFBASE VARBASE

pre-build:
	ln -sf ${FILESDIR}/glibc-compat.c ${FILESDIR}/glibc-compat.h ${WRKSRC}/

BUILD_DEFS+=	PKG_SYSCONFBASE VARBASE
MAKE_DIRS+=	${PKG_SYSCONFBASE}/incron.d
OWN_DIRS+=	${VARBASE}/spool/incron
RCD_SCRIPTS+=	incron
SPECIAL_PERMS+=	bin/incrontab ${SETUID_ROOT_PERMS}
CONF_FILES+=	\
	share/examples/incron/incron.conf.example \
	${PKG_SYSCONFBASE}/incron.conf

INSTALLATION_DIRS+=	bin sbin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	share/examples/incron

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/incrontab           ${DESTDIR}/${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/incrond             ${DESTDIR}/${PREFIX}/sbin/
	${INSTALL_MAN}     ${WRKSRC}/incrontab.1         ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN}     ${WRKSRC}/incrontab.5         ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_MAN}     ${WRKSRC}/incrond.8           ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man8/
	${INSTALL_MAN}     ${WRKSRC}/incron.conf.5       ${DESTDIR}/${PREFIX}/${PKGMANDIR}/man5/
	${INSTALL_DATA}    ${WRKSRC}/incron.conf.example ${DESTDIR}/${PREFIX}/share/examples/incron/

.include "../../devel/libinotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
