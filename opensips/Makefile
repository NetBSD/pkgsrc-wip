# $NetBSD: Makefile,v 1.4 2010/01/31 13:34:49 marttikuparinen Exp $

DISTNAME=		opensips-${VER}-tls_src
PKGNAME=		opensips-${VER}
CATEGORIES=		net
MASTER_SITES=		http://opensips.org/pub/opensips/${VER}/src/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.opensips.org/
COMMENT=		Open Source implementation of a SIP server

LICENSE=		gnu-gpl-v2

VER=			1.6.1
WRKSRC=			${WRKDIR}/opensips-${VER}-tls

USE_TOOLS+=		gmake
PKG_DESTDIR_SUPPORT=	user-destdir

CHECK_INTERPRETER_SKIP+=lib/opensips/opensipsctl/dbtextdb/dbtextdb.py
REPLACE_PERL+=		scripts/osipsconsole

.include "../../security/openssl/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
