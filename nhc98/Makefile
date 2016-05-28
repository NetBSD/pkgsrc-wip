# $NetBSD: Makefile,v 1.3 2012/10/03 18:15:32 asau Exp $

DISTNAME=		nhc98src-1.22
PKGNAME=		nhc98-1.22
#PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		http://www.haskell.org/nhc98/

MAINTAINER=		kristerw@NetBSD.org
HOMEPAGE=		http://www.haskell.org/nhc98/
COMMENT=		Portable Haskell 98 compiler

# Not yet ported to 64-bit machines
NOT_FOR_PLATFORM=	${LP64PLATFORMS}


WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}

#INCOMPAT_CURSES=	NetBSD-1.5*-* NetBSD-1.6[-_.]*-*
#INCOMPAT_CURSES+=	NetBSD-1.6[A-Z]-* NetBSD-1.6Z[A-K]*-*

HAS_CONFIGURE=		YES
CONFIGURE_ARGS+=	--buildwith=gcc --installdir=${DESTDIR}${PREFIX:Q} \
			+docs --docdir=${DESTDIR}${PREFIX}/share/doc/nhc98

USE_TOOLS+=		gmake

PLIST_SUBST+=		HARCH=`${WRKSRC}/script/harch`

do-install:
	${RUN} cd ${WRKSRC} && ${PKGSRC_SETENV} ${_CONFIGURE_SCRIPT_ENV} \
		${CONFIG_SHELL} ${CONFIGURE_SCRIPT} --install

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
