# $NetBSD: Makefile,v 1.6 2013/04/13 14:43:19 othyro Exp $
#

DISTNAME=	vlevel-0.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vlevel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vlevel.sourceforge.net/
COMMENT=	Dynamic compressor LADSPA plugin with look-ahead
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++

INSTALLATION_DIRS+=	bin lib/ladspa

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vlevel-bin ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/vlevel-ladspa.so ${DESTDIR}${BUILDLINK_PREFIX.ladspa}/lib/ladspa

.include "../../audio/ladspa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
