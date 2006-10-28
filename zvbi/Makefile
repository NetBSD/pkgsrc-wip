# $NetBSD: Makefile,v 1.5 2006/10/28 17:25:21 shattered Exp $
#

DISTNAME=		zvbi-0.2.16
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=zapping/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://zapping.sourceforge.net/Zapping/
COMMENT=		Library for accessing raw VBI sampling devices

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	${WRKSRC}/zvbi-0.2.pc.in
GNU_CONFIGURE=		yes
TEST_TARGET=		check

SUBST_CLASSES+=		putwchar
SUBST_STAGE.putwchar=	post-extract
SUBST_MESSAGE.putwchar=	Renaming conflicting function putwchar.
SUBST_FILES.putwchar=	test/glyph.c test/unicode.c
SUBST_SED.putwchar=	s/putwchar/my_putwchar/

.include "../../textproc/libunicode/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
