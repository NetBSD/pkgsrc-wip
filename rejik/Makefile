# $NetBSD: Makefile,v 1.4 2013/04/14 20:05:24 shattered Exp $
#

DISTNAME=		redirector-3.2.8
PKGNAME=		rejik-3.2.8
CATEGORIES=		www
MASTER_SITES=		http://www.rejik.ru/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		shattered@NetBSD.org
HOMEPAGE=		http://www.rejik.ru/index_en_0_0.html
COMMENT=		Banner-filtering redirector for Squid
LICENSE=		gnu-gpl-v2

NO_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	rejik
EGDIR=			share/examples/rejik
CONF_FILES=		${EGDIR}/redirector.conf.dist ${PKG_SYSCONFDIR}/redirector.conf
INSTALLATION_DIRS+=	${EGDIR} bin libexec/rejik
OWN_DIRS+=		${PKG_SYSCONFDIR}/banlists

.include "../../www/squid/Makefile.common"

MAKE_ENV+=		SQUID_USER=${SQUID_USER}
MAKE_ENV+=		SQUID_GROUP=${SQUID_GROUP}

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
