# $NetBSD: Makefile,v 1.7 2012/10/03 21:32:47 asau Exp $

DISTNAME=		opensips-${VER}-tls_src
PKGNAME=		opensips-${VER}
CATEGORIES=		net
MASTER_SITES=		http://opensips.org/pub/opensips/${VER}/src/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.opensips.org/
COMMENT=		Open Source implementation of a SIP server

LICENSE=		gnu-gpl-v2

VER=			1.6.2
WRKSRC=			${WRKDIR}/opensips-${VER}-tls

USE_TOOLS+=		gmake

CHECK_INTERPRETER_SKIP+= lib/opensips/opensipsctl/dbtextdb/dbtextdb.py
REPLACE_PERL+=		scripts/osipsconsole

PKG_SYSCONFSUBDIR=	opensips
OWN_DIRS=		${EGDIR} ${PKG_SYSCONFDIR}
EGDIR=			${PREFIX}/share/examples/opensips
CONF_FILES+=		${EGDIR}/opensips.cfg ${PKG_SYSCONFDIR}/opensips.cf
CONF_FILES+=		${EGDIR}/opensipsctlrc ${PKG_SYSCONFDIR}/opensipsctlrc
CONF_FILES+=		${EGDIR}/osipsconsolerc ${PKG_SYSCONFDIR}/osipsconsolerc

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
