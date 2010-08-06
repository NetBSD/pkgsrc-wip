# $NetBSD: Makefile,v 1.1.1.1 2010/08/06 20:25:30 jihbed Exp $
#

DISTNAME=	schur-6.05
CATEGORIES=	math
MASTER_SITES=	http://garr.dl.sourceforge.net/project/schur/sources/6.05/

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://schur.sourceforge.net/
COMMENT=	Calculating properties of Lie groups and symmetric functions
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	flex pax
USE_LANGUAGES=  c

CONFIGURE_ARGS+=	--without-readline

INSTALLATION_DIRS=	share/doc/shur

post-install:
	${INSTALL_DATA} ${WRKSRC}/manual/schur_manual.pdf \
				 ${DESTDIR}${PREFIX}/share/doc/shur

.include "../../mk/bsd.pkg.mk"
