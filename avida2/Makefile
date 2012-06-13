# $NetBSD: Makefile,v 1.12 2012/06/13 08:04:16 othyro Exp $
#

DISTNAME=	avida-2.0b1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=avida/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://avida.devosoft.org/
COMMENT=	Avida is an auto-adaptive genetic system
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

HAS_CONFIGURE=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-viewer
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake

pre-configure:
	${ECHO} DESTDIR=${PREFIX}/share/avida >> ${WRKSRC}/doc/Makefile.in; \
	${ECHO} DESTDIR=${PREFIX}/share/avida >> ${WRKSRC}/doc/glossary/Makefile.in;

post-install:
	${MV} ${PREFIX}/work ${PREFIX}/avida-2.0b1
	${LN} -s ${PREFIX}/avida-2.0b1/primitive ${PREFIX}/bin/primitive

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
