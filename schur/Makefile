# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:52 othyro Exp $
#

DISTNAME=	schur-6.05
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=schur/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://schur.sourceforge.net/
COMMENT=	Calculating properties of Lie groups and symmetric functions
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	flex pax
USE_LANGUAGES=	c

CONFIGURE_ARGS+=	--without-readline

INSTALLATION_DIRS=	share/doc/shur

post-install:
	${INSTALL_DATA} ${WRKSRC}/manual/schur_manual.pdf \
				 ${DESTDIR}${PREFIX}/share/doc/shur

.include "../../mk/bsd.pkg.mk"
