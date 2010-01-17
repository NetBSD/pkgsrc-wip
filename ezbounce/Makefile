# $NetBSD: Makefile,v 1.22 2010/01/17 12:03:25 thomasklausner Exp $
#

DISTNAME=	ezbounce-1.99.14
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	http://www.linuxftw.com/ezbounce/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linuxftw.com/ezbounce/
COMMENT=	Highly Configurable IRC Proxy

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-ssl

EGDIR=		${PREFIX}/share/examples/ezbounce
DOCDIR=		${PREFIX}/share/doc/ezbounce

EZBOUNCE_USER=		ezbounce
EZBOUNCE_GROUP=		ezbounce

PKG_GROUPS=		${EZBOUNCE_GROUP}
PKG_USERS=		${EZBOUNCE_USER}:${EZBOUNCE_GROUP}::Ezbounce\ user

RCD_SCRIPTS=		ezbounce

CONF_FILES=	${EGDIR}/ezbounce.conf.default ${PKG_SYSCONFDIR}/ezbounce.conf

INSTALLATION_DIRS+=	${EGDIR} ${DOCDIR} sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ezbounce ${WRKSRC}/mdidentd/mdidentd \
	  ${DESTDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/ezbchk ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/ezb.conf \
	  ${DESTDIR}${EGDIR}/ezbounce.conf.default
	${INSTALL_DATA} ${WRKSRC}/misc/ezbounce.1 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	( cd ${WRKSRC} && for f in README* TODO CHANGES sample.conf sample.MOTD; do \
		${INSTALL_DATA} $$f ${DESTDIR}${DOCDIR}; \
	done )

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
