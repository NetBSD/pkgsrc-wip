# $NetBSD: Makefile,v 1.4 2014/11/09 21:02:11 thomasklausner Exp $

DISTNAME=	mu-1.4.13
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GITHUB:=djcb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.djcbsoftware.nl/code/mu/
COMMENT=	E-mail searching and indexing tools
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config autoconf automake autoreconf

.include "options.mk"

pre-configure:
	cd ${WRKSRC} && autoreconf -fiv

post-install:
	-${RM} -f ${DESTDIR}${PREFIX}/info/dir

.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../mail/gmime3/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
