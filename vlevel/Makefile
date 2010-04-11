# $NetBSD: Makefile,v 1.2 2010/04/11 09:06:16 obache Exp $
#

DISTNAME=	vlevel-0.5
CATEGORIES=	audio
MASTER_SITES=	http://downloads.sourceforge.net/vlevel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vlevel.sourceforge.net/
COMMENT=	Dynamic compressor LADSPA plugin with look-ahead
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/vlevel-0.5
USE_LANGUAGES=	c++

do-install:
	${INSTALL_PROGRAM_DIR} ${PREFIX}
	${INSTALL_PROGRAM} ${WRKSRC}/vlevel-bin ${PREFIX}/bin
	${INSTALL_LIB_DIR} ${BUILDLINK_PREFIX.ladspa}/lib/ladspa
	${INSTALL_LIB} ${WRKSRC}/vlevel-ladspa.so ${BUILDLINK_PREFIX.ladspa}/lib/ladspa

.include "../../audio/ladspa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
