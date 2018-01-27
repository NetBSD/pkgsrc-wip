# $NetBSD: Makefile,v 1.3 2012/10/05 13:52:03 asau Exp $
#

DISTNAME=	psyBNC-2.3.2-9
CATEGORIES=	chat
MASTER_SITES=	http://www.psybnc.at/download/beta/

MAINTAINER=	pettai@nordu.net
HOMEPAGE=	http://www.psybnc.at/
COMMENT=	Easy-to-use, multi-user, permanent IRC-Bouncer with many features
LICENSE=	gnu-gpl-v2

WRKSRC=	${WRKDIR}/psybnc

BUILD_DEPENDS+=		glib-[0-9]*:../../devel/glib

USE_TOOLS+=	gmake

CONF_FILES=		share/examples/psybnc/psybnc.conf \
                        ${PKG_SYSCONFDIR}/psybnc.conf

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	tools/autoconf.c
SUBST_SED.prefix=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_STAGE.prefix=	post-patch
SUBST_CLASSES+=		openssl
SUBST_FILES.openssl=	makefile.out
SUBST_SED.openssl=	-e "s|/usr/bin/openssl|@echo openssl|g"
SUBST_STAGE.openssl=	pre-build

INSTALLATION_DIRS=	bin share/examples/psybnc
INSTALLATION_DIRS+=	share/doc/psybnc

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${GMAKE}

do-build:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
	${GMAKE} -f makefile.out

do-install:
	${INSTALL_DATA} ${WRKSRC}/psybnc \
			${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/FAQ \
			${DESTDIR}${PREFIX}/share/doc/psybnc
	${INSTALL_DATA} ${WRKSRC}/README \
			${DESTDIR}${PREFIX}/share/doc/psybnc
	${INSTALL_DATA} ${WRKSRC}/SCRIPTING \
			${DESTDIR}${PREFIX}/share/doc/psybnc
	${INSTALL_DATA} ${WRKSRC}/psybnc.conf \
			${DESTDIR}${PREFIX}/share/examples/psybnc

#.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
