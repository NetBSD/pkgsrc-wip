# $NetBSD: Makefile,v 1.15 2012/10/01 22:12:50 asau Exp $

DISTNAME=	l2tpd-0.69
CATEGORIES=	net
MASTER_SITES=	http://l2tpd.sourceforge.net/l2tpd.org/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://l2tpd.sourceforge.net/
# NOTE: "The l2tpd project is now officially inactive"
COMMENT=	Implementation of the layer two tunneling protocol (l2tp)

NO_CONFIGURE=	YES

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFSUBDIR?=	l2tpd
DOCDIR=			${PREFIX}/share/doc/l2tpd
EGDIR=			${PREFIX}/share/examples/l2tpd
CONF_FILES=		${EGDIR}/l2tpd.conf.sample ${PKG_SYSCONFDIR}/l2tpd.conf
CONF_FILES+=		${EGDIR}/l2tp-secrets.sample ${PKG_SYSCONFDIR}/l2tpd-secrets

CFLAGS+=	-DPREFIX=\"${PREFIX}\" -DSANITY

SUBST_CLASSES+=		options
SUBST_MESSAGE.options=	Fixing build options.
SUBST_STAGE.options=	post-patch
SUBST_FILES.options=	Makefile
SUBST_SED.options=	-e 's,DFLAGS=,\#DFLAGS=,' \
			-e 's,OSFLAGS=,\#OSFLAGS=,' \
			-e 's,CFLAGS=,\#CFLAGS=,' \
			-e 's,(LIBS),(LDFLAGS),'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "FreeBSD"
CFLAGS+=		-DFREEBSD
.elif ${OPSYS} == "SunOS"
CFLAGS+=		-DSOLARIS
LDFLAGS+=		-lnsl -lsocket
.elif ${OPSYS} == "Linux"
CFLAGS+=		-DLINUX -I/usr/include
.endif

SUBST_CLASSES+=		l2tpd
SUBST_STAGE.l2tpd=	post-patch
SUBST_FILES.l2tpd+=	doc/l2tpd.8 doc/l2tpd.conf.sample
SUBST_FILES.l2tpd+=	doc/l2tp-secrets.5 doc/l2tpd.conf.5
SUBST_SED.l2tpd+=	-e 's|%%SYSCONFDIR%%|${PKG_SYSCONFDIR}|g'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man5 ${PKGMANDIR}/man8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/l2tpd ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR:Q}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${DOCDIR:Q}
	${INSTALL_MAN} ${WRKSRC}/doc/l2tpd.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_MAN} ${WRKSRC}/doc/l2tp-secrets.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN} ${WRKSRC}/doc/l2tpd.conf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/l2tpd.conf.sample ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/l2tp-secrets.sample ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
