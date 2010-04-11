# $NetBSD: Makefile,v 1.3 2010/04/11 09:10:44 obache Exp $
#

DISTNAME=	vlevel-0.5
CATEGORIES=	audio
MASTER_SITES=	http://downloads.sourceforge.net/vlevel/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://vlevel.sourceforge.net/
COMMENT=	Dynamic compressor LADSPA plugin with look-ahead
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/vlevel-0.5
USE_LANGUAGES=	c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vlevel-bin ${DESTDIR}${PREFIX}/bin
	${INSTALL_LIB_DIR} ${DESTDIR}${BUILDLINK_PREFIX.ladspa}/lib/ladspa
	${INSTALL_LIB} ${WRKSRC}/vlevel-ladspa.so ${DESTDIR}${BUILDLINK_PREFIX.ladspa}/lib/ladspa

.include "../../audio/ladspa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
