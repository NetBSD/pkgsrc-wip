# $NetBSD: Makefile,v 1.1 2012/08/12 17:38:42 trontor Exp $

DISTNAME=	Radicale-0.7.1
PKGNAME=	${DISTNAME:S/R/r/}
CATEGORIES=	www
MASTER_SITES=	http://pypi.python.org/packages/source/R/Radicale/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://radicale.org/
COMMENT=	CalDAV (calendar) and CardDAV (contact) server
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir
PYDISTUTILSPKG=		yes

EGDIR=			share/examples/radicale

INSTALLATION_DIRS=	${EGDIR}
OWN_DIRS=		${PKG_SYSCONFDIR}/radicale
CONF_FILES+=		${EGDIR}/config ${PKG_SYSCONFDIR}/radicale/config

post-build:
	${SED} -e "s#/etc#${PKG_SYSCONFDIR}#" -e "s#apache2/#httpd/#" \
	  ${WRKSRC}/config >${WRKSRC}/config.pkgsrc

post-install:
	${INSTALL_DATA} ${WRKSRC}/config.pkgsrc \
	  ${DESTDIR}${PREFIX}/${EGDIR}/config

.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
