# $NetBSD: Makefile,v 1.10 2013/02/17 21:19:26 othyro Exp $
#

DISTNAME=	uade-2.13
PKGREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://zakalwe.fi/uade/uade2/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://zakalwe.fi/uade/
COMMENT=	Unix Amiga Delitracker Emulator
LICENSE=	gnu-gpl-v2

USE_PKGLOCALEDIR=	yes
HAS_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

CONFIGURE_ARGS+=	--prefix=${PREFIX} --mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--with-text-scope

.include "options.mk"

post-install:
	for i in AMOS AudioSculpture Infogrames MED Medley PTK-Prowiz \
		Soundtracker-IV; do \
		${CHMOD} -x ${DESTDIR}${PREFIX}/share/uade2/players/$$i; \
	done
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/uade2/players/ENV/EaglePlayer/*

.include "../../audio/libao/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
