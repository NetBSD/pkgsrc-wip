# $NetBSD: Makefile,v 1.4 2007/06/21 13:09:17 bartoszkuzma Exp $
#

PKGVERSION=		1.68

DISTNAME=		yaws-${PKGVERSION}
CATEGORIES=		www
MASTER_SITES=		http://yaws.hyber.org/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://yaws.hyber.org/
COMMENT=		High perfomance HTTP 1.1 webserver written in Erlang

BUILD_DEFS+=		VARBASE

USE_TOOLS+=		gmake perl
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/yaws
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

EGDIR=			${PREFIX}/share/examples/yaws
CONF_FILES=		${EGDIR}/yaws.conf ${PKG_SYSCONFDIR}/yaws/yaws.conf
RCD_SCRIPTS=		yaws
RCD_SCRIPT_SRC.yaws=	${WRKSRC}/scripts/netbsd/yaws.sh

DOCDIR=			${PREFIX}/share/doc/yaws
LIBDIR=			${PREFIX}/lib/yaws
WWWDIR=			${PREFIX}/share/yaws/www
INSTALLATION_DIRS=	${DOCDIR} ${EGDIR}
INSTALLATION_DIRS+=	${LIBDIR}/ebin ${LIBDIR}/include
INSTALLATION_DIRS+=	${LIBDIR}/priv ${WWWDIR}

OWN_DIRS=		${VARBASE}/log/yaws

post-patch:
	${RM} ${WRKDIR}/yaws
	${RM} -Rf ${WRKSRC}/www/.xvpics
	${RM} -Rf ${WRKSRC}/www/testdir
	${FIND} ${WRKSRC} -name \*.orig -or -name .empty | ${XARGS} ${RM}

post-configure:
	${SED} -e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g" \
		-e "s|@PREFIX@|${PREFIX}|g" \
		-e "s|@VARBASE@|${VARBASE}|g" \
		${FILESDIR}/yaws.conf > ${WRKDIR}/yaws.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/yaws ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/yaws.conf ${EGDIR}

	${INSTALL_DATA} ${WRKSRC}/ebin/* ${LIBDIR}/ebin
	${INSTALL_DATA} ${WRKSRC}/include/* ${LIBDIR}/include
	${INSTALL_DATA} ${WRKSRC}/priv/* ${LIBDIR}/priv

	${INSTALL_DATA} ${WRKSRC}/doc/yaws.pdf ${DOCDIR}

	cd ${WRKSRC}/www && ${PAX} -rw . ${WWWDIR}

	${INSTALL_MAN} ${WRKSRC}/man/yaws.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/*.5 ${PREFIX}/${PKGMANDIR}/man5

	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}/yaws

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
