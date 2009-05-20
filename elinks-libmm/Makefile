# $NetBSD: Makefile,v 1.2 2009/05/20 00:58:40 thomasklausner Exp $

DISTNAME=		elinks-current-0.13
PKGNAME=		elinks-0.13
PKGREVISION=		1
CATEGORIES=		www
MASTER_SITES=		http://elinks.or.cz/download/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://elinks.or.cz/
COMMENT=		Extended/Enhanced Links

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

CONFIGURE_ARGS+=	--datadir=${ELINKS_DATADIR:Q}
CONFGIURE_ARGS+=	--enable-utf-8=yes

ELINKS_DATADIR=		${PREFIX}/share/${PKGBASE}
ELINKS_LOCALEDIR=	${ELINKS_DATADIR}/locale

CONFIGURE_ENV+=		AUTOCONF=${TRUE}
CONFIGURE_ENV+=		AUTOMAKE=${TRUE}
MAKE_ENV+=		PKGLOCALEDIR=${ELINKS_LOCALEDIR:Q}

LIBS+=			-lmm

.include "options.mk"

post-extract:
	${MV} ${WRKDIR}/elinks-0.13-* ${WRKDIR}/${PKGNAME_NOREV}
	${CP} ${FILESDIR}/malloca.?   ${WRKSRC}/src/util

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libmm/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
