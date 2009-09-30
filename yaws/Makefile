# $NetBSD: Makefile,v 1.10 2009/09/30 13:50:26 fhajny Exp $
#

PKGVERSION=		1.84

DISTNAME=		yaws-${PKGVERSION}
CATEGORIES=		www
MASTER_SITES=		http://yaws.hyber.org/download/

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://yaws.hyber.org/
COMMENT=		High perfomance HTTP 1.1 webserver written in Erlang

BUILD_DEFS+=		VARBASE

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake perl pax
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}/yaws
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

EGDIR=			${PREFIX}/share/examples/yaws
CONF_FILES=		${EGDIR}/yaws.conf ${PKG_SYSCONFDIR}/yaws/yaws.conf
RCD_SCRIPTS=		yaws
RCD_SCRIPT_SRC.yaws=	${WRKSRC}/scripts/netbsd/yaws.sh

LIBDIR=			${PREFIX}/lib/yaws
WWWDIR=			${PREFIX}/share/yaws/www
INSTALLATION_DIRS=	${EGDIR}
INSTALLATION_DIRS+=	${LIBDIR}/ebin ${LIBDIR}/include
INSTALLATION_DIRS+=	${LIBDIR}/priv ${LIBDIR}/priv/lib ${WWWDIR}

OWN_DIRS=		${VARBASE}/log/yaws

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == SunOS
REPLACE_INTERPRETER+=	ksh
REPLACE.ksh.old=	/bin/sh
REPLACE.ksh.new=	/bin/ksh
REPLACE_FILES.ksh=	scripts/Subst
.endif

REPLACE_INTERPRETER+=	python
REPLACE.python.old=	.*/bin/python
REPLACE.python.new=	${PREFIX}/bin/python
REPLACE_FILES.python=	www/cgi-bin/foo.py

post-patch:
	${RM} ${WRKDIR}/yaws
	${RM} -Rf ${WRKSRC}/www/.xvpics
	${RM} -Rf ${WRKSRC}/www/testdir
	${FIND} ${WRKSRC} -name \*.orig -o -name .empty | ${XARGS} ${RM}

post-configure:
	${SED} -e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g" \
		-e "s|@PREFIX@|${PREFIX}|g" \
		-e "s|@VARBASE@|${VARBASE}|g" \
		${FILESDIR}/yaws.conf > ${WRKDIR}/yaws.conf

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/yaws ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/yaws.conf ${DESTDIR}${EGDIR}

	${INSTALL_DATA} ${WRKSRC}/ebin/* ${DESTDIR}${LIBDIR}/ebin
	${INSTALL_DATA} ${WRKSRC}/include/* ${DESTDIR}${LIBDIR}/include
	cd ${WRKSRC}/priv && pax -rw . ${DESTDIR}${LIBDIR}/priv
	${INSTALL_DATA} ${WRKSRC}/priv/lib/setuid_drv.so ${DESTDIR}${LIBDIR}/priv/lib/setuid_drv.so
	${INSTALL_DATA} ${WRKSRC}/priv/envelope.xsd ${DESTDIR}${LIBDIR}/priv/envelope.xsd
	${INSTALL_DATA} ${WRKSRC}/priv/epam ${DESTDIR}${LIBDIR}/priv/epam
	${INSTALL_DATA} ${WRKSRC}/priv/mime.types ${DESTDIR}${LIBDIR}/priv/mime.types
	${INSTALL_DATA} ${WRKSRC}/priv/soap.xsd ${DESTDIR}${LIBDIR}/priv/soap.xsd
	${INSTALL_DATA} ${WRKSRC}/priv/wsdl.xsd ${DESTDIR}${LIBDIR}/priv/wsdl.xsd

	cd ${WRKSRC}/www && pax -rw . ${DESTDIR}${WWWDIR}

	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/man/yaws.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/man/*.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5

	${INSTALL_DATA_DIR} ${DESTDIR}${PKG_SYSCONFDIR}/yaws

.include "../../lang/erlang/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
