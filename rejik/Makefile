# $NetBSD: Makefile,v 1.1.1.1 2012/02/18 15:17:30 shattered Exp $
#

DISTNAME=		redirector-3.2.8
PKGNAME=		rejik-3.2.8
CATEGORIES=		www
MASTER_SITES=		http://www.rejik.ru/download/
EXTRACT_SUFX=		.tgz

MAINTAINER=		shattered@users.sourceforge.net
HOMEPAGE=		http://www.rejik.ru/index_en_0_0.html
COMMENT=		Banner-filtering redirector for Squid
LICENSE=		gnu-gpl-v2

NO_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	rejik
EGDIR=			${PREFIX}/share/examples/rejik
CONF_FILES=		${EGDIR}/redirector.conf.dist ${PKG_SYSCONFDIR}/redirector.conf
INSTALLATION_DIRS+=	${EGDIR}
INSTALLATION_DIRS+=	${PREFIX}/libexec/rejik
OWN_DIRS+=		${PKG_SYSCONFDIR}/banlists

.include "../../www/squid/Makefile.common"

MAKE_ENV+=		SQUID_USER=${SQUID_USER:Q}
MAKE_ENV+=		SQUID_GROUP=${SQUID_GROUP:Q}

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
