# $NetBSD: Makefile,v 1.25 2013/01/20 22:12:46 othyro Exp $
#

DISTNAME=	ezbounce-1.99.15
CATEGORIES=	chat
MASTER_SITES=	http://www.linuxftw.com/ezbounce/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.linuxftw.com/ezbounce/
COMMENT=	Highly Configurable IRC Proxy
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake makedepend

EGDIR=		${PREFIX}/share/examples/ezbounce
DOCDIR=		${PREFIX}/share/doc/ezbounce

PKG_DESTDIR_SUPPORT=	destdir

EZBOUNCE_USER=	ezbounce
EZBOUNCE_GROUP=	ezbounce
PKG_GROUPS=	${EZBOUNCE_GROUP}
PKG_USERS=	${EZBOUNCE_USER}:${EZBOUNCE_GROUP}::Ezbounce\ user

RCD_SCRIPTS=	ezbounce

CONF_FILES=	${EGDIR}/ezbounce.conf.default ${PKG_SYSCONFDIR}/ezbounce.conf

INSTALLATION_DIRS+=	${EGDIR} ${PKGMANDIR}/man1 ${DOCDIR} sbin

.include "options.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ezbounce ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_SCRIPT} ${WRKSRC}/tools/ezbchk ${DESTDIR}${PREFIX}/sbin/
	${INSTALL_DATA} ${WRKSRC}/ezb.conf \
	  ${DESTDIR}${EGDIR}/ezbounce.conf.default
	${INSTALL_DATA} ${WRKSRC}/docs/ezbounce.1 \
	  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	( cd ${WRKSRC} && for f in README TODO CHANGES motd.txt sample.conf; do \
		${INSTALL_DATA} $$f ${DESTDIR}${DOCDIR}; \
	done )

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
