# $NetBSD: Makefile,v 1.4 2004/01/08 04:11:30 bjan2 Exp $

DISTNAME=		elinks-0.9.0
CATEGORIES=		www
MASTER_SITES=		http://elinks.or.cz/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		dawszy@arhea.net
HOMEPAGE=		http://elinks.or.cz/
COMMENT=		Extended/Enhanced Links

CONFLICTS=		elinks-[0-9]*

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_PKGLOCALEDIR=	yes

PKG_SYSCONFSUBDIR=	elinks
EGDIR=			share/examples/${PKGBASE}
PLIST_SUBST+=		PKG_SYSCONFDIR=${PKG_SYSCONFDIR} EGDIR=${EGDIR}

CONFIGURE_ARGS+=	--without-x
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../lang/lua/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

post-install:
	${INSTALL_DATA_DIR} ${PKG_SYSCONFDIR}
	${TOUCH} ${PKG_SYSCONFDIR}/hooks.lua
	${INSTALL_DATA_DIR} ${PREFIX}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/lua/hooks.lua ${PREFIX}/${EGDIR}

.include "../../mk/bsd.pkg.mk"
